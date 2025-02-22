// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file QuaternionPubSubTypes.h
 * This header file contains the declaration of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */
// 防止头文件被重复包含，如果 _FAST_DDS_GENERATED_GEOMETRY_MSGS_MSG_QUATERNION_PUBSUBTYPES_H_ 未定义，则定义它
// 这是一种常见的头文件保护机制，确保该头文件内容只被编译一次
#ifndef _FAST_DDS_GENERATED_GEOMETRY_MSGS_MSG_QUATERNION_PUBSUBTYPES_H_
#define _FAST_DDS_GENERATED_GEOMETRY_MSGS_MSG_QUATERNION_PUBSUBTYPES_H_
// 包含 Fast DDS 中定义主题数据类型相关的头文件
#include <fastdds/dds/topic/TopicDataType.hpp>
// 包含 Fast RTPS 中用于计算 MD5 的工具头文件
#include <fastrtps/utils/md5.h>
// 包含自定义的 Quaternion 类型的头文件，可能是用户定义的表示四元数的数据结构所在头文件
#include "Quaternion.h"
// 如果未定义 GEN_API_VER 或者 GEN_API_VER 的值不等于 1
#if !defined(GEN_API_VER) || (GEN_API_VER != 1)
// 输出错误信息，表示生成的 Quaternion 与当前安装的 Fast DDS 不兼容，提示使用 fastddsgen 重新生成
#error \
    Generated Quaternion is not compatible with current installed Fast DDS. Please, regenerate it with fastddsgen.
#endif  // GEN_API_VER
// 定义命名空间 geometry_msgs，通常用于对相关的消息类型等进行组织和分类
namespace geometry_msgs
{
// 在 geometry_msgs 命名空间内再定义 msg 命名空间，进一步细分消息相关的内容
    namespace msg
    {
// 如果没有定义 SWIG（SWIG 通常用于不同编程语言间的接口生成等情况）
        #ifndef SWIG
        namespace detail {
// 定义一个模板结构体 Quaternion_rob，用于通过 Tag 获取特定类型的值
            // Tag 是一个模板参数类型，M 是 Tag 类型中的成员类型

            template<typename Tag, typename Tag::type M>
            struct Quaternion_rob
            {
// 定义友元函数 get，用于返回 M 的值，方便外部获取该模板实例化时指定的成员值
                friend constexpr typename Tag::type get(
                        Tag)
                {
                    return M;
                }
            };
// 定义结构体 Quaternion_f，其内部定义了一个类型别名 type，用于指向 Quaternion 类中成员的指针类型（这里具体指向 double 类型成员的指针）
            struct Quaternion_f
            {
                typedef double Quaternion::* type;
                friend constexpr type get(
                        Quaternion_f);
            };
 // 对 Quaternion_rob 模板进行实例化，指定了获取 Quaternion 类中 m_w 成员（这里推测是 double 类型成员）的相关配置
            template struct Quaternion_rob<Quaternion_f, &Quaternion::m_w>;
// 定义一个模板函数 Quaternion_offset_of，用于计算类型 T 中通过 Tag 获取的成员的偏移量
            template <typename T, typename Tag>
            inline size_t constexpr Quaternion_offset_of() {
                // 通过一些复杂的指针操作和类型转换来计算偏移量，这里将 0 地址强制转换为 T* 类型，再通过获取 Tag 指定的成员指针来获取其相对地址偏移
                return ((::size_t) &reinterpret_cast<char const volatile&>((((T*)0)->*get(Tag()))));
            }
        }
        #endif

      // 下面的类 QuaternionPubSubType 用于表示在 IDL 文件中用户定义的 Quaternion 类型的主题数据类型
        // 它继承自 eprosima::fastdds::dds::TopicDataType，实现了与该类型数据在 Fast DDS 中的发布订阅相关的一系列操作接口
        // @ingroup QUATERNION 表示这个类属于 QUATERNION 分组（可能在文档生成等场景用于归类相关内容）
        class QuaternionPubSubType : public eprosima::fastdds::dds::TopicDataType
        {
        public:
// 定义类型别名 type，指向 Quaternion 类型，表明这个发布订阅类型对应的实际数据类型是 Quaternion
            typedef Quaternion type;
// 构造函数，用于初始化 QuaternionPubSubType 类型的对象，可能进行一些内部数据结构的初始化等操作
            // 标记为 eProsima_user_DllExport，可能用于在动态链接库导出相关场景

            eProsima_user_DllExport QuaternionPubSubType();
// 析构函数，用于清理 QuaternionPubSubType 类型对象占用的资源，例如释放内存等
            // 标记为 virtual 表示是虚函数，可在派生类中进行重写；标记为 override 表示重写了基类的虚函数
            eProsima_user_DllExport virtual ~QuaternionPubSubType() override;
// 用于将 Quaternion 类型的数据进行序列化，将其转换为适合在网络等传输的字节流形式（存储在 SerializedPayload_t 结构体中）
            // 如果序列化成功返回 true，否则返回 false
            eProsima_user_DllExport virtual bool serialize(
                    void* data,
                    eprosima::fastrtps::rtps::SerializedPayload_t* payload) override;
// 用于将接收到的字节流（SerializedPayload_t 结构体表示）反序列化还原为 Quaternion 类型的数据
            // 如果反序列化成功返回 true，否则返回 false
            eProsima_user_DllExport virtual bool deserialize(
                    eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                    void* data) override;
// 返回一个函数对象（std::function），该函数对象调用时能获取给定 Quaternion 数据序列化后的大小
            eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
                    void* data) override;
// 根据给定的 Quaternion 数据获取其对应的键（用于在发布订阅系统中区分不同实例等情况）
            // 如果获取键成功返回 true，否则返回 false，可选择是否强制使用 MD5 方式来获取键（默认不强制）
            eProsima_user_DllExport virtual bool getKey(
                    void* data,
                    eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
                    bool force_md5 = false) override;
 // 创建一个 Quaternion 类型的数据空间，返回指向该空间的指针，通常用于在发布订阅过程中准备存储数据的内存区域
            eProsima_user_DllExport virtual void* createData() override;
// 释放由 createData 创建的数据空间占用的内存资源，确保内存正确回收
            eProsima_user_DllExport virtual void deleteData(
                    void* data) override;

        #ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
 // 判断该数据类型是否有界（在某些发布订阅系统的语义中有相关概念，比如数据长度是否固定等情况）
            // 如果是返回 true，这里直接返回 true，说明 QuaternionPubSubType 对应的类型是有界的
            eProsima_user_DllExport inline bool is_bounded() const override
            {
                return true;
            }

        #endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

        #ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
// 判断该数据类型是否是简单类型（同样是在发布订阅系统相关语义下的概念）
            // 通过调用私有函数 is_plain_impl 来判断并返回结果
            eProsima_user_DllExport inline bool is_plain() const override
            {
                return is_plain_impl();
            }

        #endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

        #ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
// 在给定的内存区域（memory 指针指向的空间）构造一个 Quaternion 类型的数据实例
            // 这里通过 placement new 的方式调用 Quaternion 的默认构造函数来构造实例，成功返回 true
            eProsima_user_DllExport inline bool construct_sample(
                    void* memory) const override
            {
                new (memory) Quaternion();
                return true;
            }

        #endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
// 用于存储计算出的 MD5 值，可能在获取键等操作中用于数据的唯一性验证等情况
            MD5 m_md5;
// 指向存储键数据的缓冲区的指针，用于缓存获取到的键数据
            unsigned char* m_keyBuffer;
        private:
// 私有静态函数，用于判断该数据类型是否是简单类型的具体实现逻辑
            // 通过比较 Quaternion 类型中相关成员的偏移量和预期大小来判断（这里预期是 32ULL）
            static constexpr bool is_plain_impl()
            {
                return 32ULL == (detail::Quaternion_offset_of<Quaternion, detail::Quaternion_f>() + sizeof(double));

            }};
    }
}
// 结束头文件保护，与开头的 #ifndef 对应，确保头文件内容只被编译一次
#endif // _FAST_DDS_GENERATED_GEOMETRY_MSGS_MSG_QUATERNION_PUBSUBTYPES_H_
