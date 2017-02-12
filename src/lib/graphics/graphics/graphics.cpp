/******************************************************************************/
/*
  Author  - Ming-Lun "Allen" Chou
  Web     - http://AllenChou.net
  Twitter - @TheAllenChou
 */
/******************************************************************************/

#include "graphics/graphics.h"

#include "util/macro-util.h"

static GLFWwindow* s_pWindow = nullptr;

void InitWindow(unsigned width, unsigned height, const char* title)
{
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  s_pWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

bool WindowShouldClose()
{
  return glfwWindowShouldClose(s_pWindow) != 0;
}

void PollWindowEvent()
{
  glfwPollEvents();
}

void DestroyWindow()
{
  glfwDestroyWindow(s_pWindow);
  glfwTerminate();
}

static VkResult InitVulkanInstance(VkInstanceHandle& hInstance)
{
#ifdef NDEBUG
  const bool useValidationLayers = false;
#else
  const bool useValidationLayers = true;

  const char* aDesiredValidationLayers[] = 
  {
    "VK_LAYER_LUNARG_standard_validation"
  };
  const char* aFoundValidationLayers[ARRAY_COUNT(aDesiredValidationLayers)];
  uint32_t numFoundValidationLayers = 0;
  if (useValidationLayers)
  {
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    for (const char* layerName : aDesiredValidationLayers)
      for (const auto& layerProperties : availableLayers)
        if (!strcmp(layerName, layerProperties.layerName))
          aFoundValidationLayers[numFoundValidationLayers++] = layerName;
  }
#endif
  
  unsigned glfwExtensionCount = 0;
  const char **glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  VkApplicationInfo appInfo = {};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Hello Triangle";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;
  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;
  createInfo.enabledLayerCount = 0;
  if (useValidationLayers)
  {
    createInfo.enabledLayerCount = numFoundValidationLayers;
    createInfo.ppEnabledLayerNames = aFoundValidationLayers;
  }

  uint32_t vkExtensionCount = 0;
  vkEnumerateInstanceExtensionProperties(nullptr, &vkExtensionCount, nullptr);
  std::cout << vkExtensionCount << " extensions supported" << std::endl;

  return vkCreateInstance(&createInfo, nullptr, &hInstance);
}

VkResult InitVulkan(VkInstanceHandle& hInstance)
{
  if (const VkResult result = InitVulkanInstance(hInstance))
    return result;

  return VK_SUCCESS;
}

