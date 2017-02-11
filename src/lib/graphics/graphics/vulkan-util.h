/******************************************************************************/
/*
  Author  - Ming-Lun "Allen" Chou
  Web     - http://AllenChou.net
  Twitter - @TheAllenChou
 */
/******************************************************************************/

#ifndef VULKAN_UTIL_H
#define VULKAN_UTIL_H

#include <vulkan/vulkan.h>

template <typename VkType>
struct VkDeleteFunc
{
  typedef void (*Type)(VkType, const VkAllocationCallbacks*);
};

template <typename VkType, typename VkDeleteFunc<VkType>::Type DeleteFunc, const VkAllocationCallbacks* AllocFunc = nullptr>
class VkHandle
{
  private:

    struct Deleter
    {
      Deleter() : m_data(VK_NULL_HANDLE) { }
      Deleter(VkType handle) : m_data(handle) { }
      ~Deleter() { DeleteFunc(m_data, AllocFunc); }
      VkType m_data;
    };

    std::shared_ptr<Deleter> m_pDeleter;

  public:

    VkHandle() : m_pDeleter(new Deleter()) { }
    VkHandle(const VkHandle& rhs) : m_pDeleter(rhs.m_pDeleter) { }

    VkType* operator&() { return &m_pDeleter->m_data; }
    const VkType* operator&() const { return &m_pDeleter->m_data; }

    void Clear() { m_pDeleter = nullptr; }
};

typedef VkHandle<VkInstance, vkDestroyInstance> VkInstanceHandle;

#endif
