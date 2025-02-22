// Copyright (c) 2023 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "CarlaRecorderDoorVehicle.h"
#include "CarlaRecorder.h"
#include "CarlaRecorderHelpers.h"


void CarlaRecorderDoorVehicle::Write(std::ostream &OutFile)
{
    // 写入数据库 ID，类型为 uint32_t（无符号 32 位整数）
    WriteValue<uint32_t>(OutFile, this->DatabaseId);

    // 写入车辆门的类型，类型为 VehicleDoorType（自定义的枚举或类，表示车辆门的类型）
    WriteValue<VehicleDoorType>(OutFile, this->Doors);

    // 写入一个布尔值，表示门是否打开，类型为 bool（布尔值）
    WriteValue<bool>(OutFile, this->bIsOpen);
}

void CarlaRecorderDoorVehicle::Read(std::istream &InFile)
{
  // database id
  ReadValue<uint32_t>(InFile, this->DatabaseId);
  ReadValue<VehicleDoorType>(InFile, this->Doors);
  ReadValue<bool>(InFile, this->bIsOpen);
}

// ---------------------------------------------

void CarlaRecorderDoorVehicles::Clear(void)
{
  Vehicles.clear();
}

void CarlaRecorderDoorVehicles::Add(const CarlaRecorderDoorVehicle &Vehicle)
{
  Vehicles.push_back(Vehicle);
}

void CarlaRecorderDoorVehicles::Write(std::ostream &OutFile)
{
  // write the packet id
  WriteValue<char>(OutFile, static_cast<char>(CarlaRecorderPacketId::VehicleDoor));

  // write a dummy packet size
  uint32_t Total = 2 + Vehicles.size() * sizeof(CarlaRecorderDoorVehicle);
  WriteValue<uint32_t>(OutFile, Total);

  // write total records
  Total = Vehicles.size();
  WriteValue<uint16_t>(OutFile, Total);

  for (auto& Vehicle : Vehicles)
  {
    Vehicle.Write(OutFile);
  }
}

void CarlaRecorderDoorVehicles::Read(std::istream &InFile)
{
  uint16_t Total;
  CarlaRecorderDoorVehicle DoorVehicle;

  // read Total walkers
  ReadValue<uint16_t>(InFile, Total);
  for (uint16_t i = 0; i < Total; ++i)
  {
    DoorVehicle.Read(InFile);
    Add(DoorVehicle);
  }
}

const std::vector<CarlaRecorderDoorVehicle>& CarlaRecorderDoorVehicles::GetDoorVehicles()
{
  return Vehicles;
}
