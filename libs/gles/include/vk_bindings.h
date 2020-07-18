// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See vk_bindings_generator.py for modifications

/*
\brief Vk Vulkan function pointers.
\file vk_bindings.h
\author PowerVR by Imagination, Developer Technology Team
\copyright Copyright (c) Imagination Technologies Limited.
*/

#pragma once
#ifndef VK_PROTOTYPES
#define VK_NO_PROTOTYPES 1
#endif
#if defined(VK_USE_PLATFORM_MACOS_MVK)
#include "MoltenVK/vk_mvk_moltenvk.h"
#else

#include "vulkan/vulkan.h"

#endif

typedef PFN_vkVoidFunction (VKAPI_PTR *PFN_GetPhysicalDeviceProcAddr)(VkInstance instance, const char *pName);

// Vulkan function pointer table
typedef struct VkBindings_ {
    // ---- Before using Vulkan, an application must initialize it by loading the Vulkan commands, and creating a VkInstance object.

    // ---- This function table provides the functions necessary for achieving this.
    PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
    PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
    PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
    PFN_vkCreateInstance vkCreateInstance;
    PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;

// ---- Functions required for MoltenVK MVKConfiguration functionality.
#ifdef VK_USE_PLATFORM_MACOS_MVK
    PFN_vkSetMoltenVKConfigurationMVK vkSetMoltenVKConfigurationMVK;
    PFN_vkGetMoltenVKConfigurationMVK vkGetMoltenVKConfigurationMVK;
#endif

} VkBindings;

// Instance function pointers
typedef struct VkInstanceBindings_ {
    // Manually add in vkGetPhysicalDeviceProcAddr entry
    PFN_GetPhysicalDeviceProcAddr vkGetPhysicalDeviceProcAddr;

    // ---- Core 1_0 commands
    PFN_vkCreateInstance vkCreateInstance;
    PFN_vkDestroyInstance vkDestroyInstance;
    PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
    PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
    PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
    PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties;
    PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
    PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
    PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
    PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
    PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
    PFN_vkCreateDevice vkCreateDevice;
    PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
    PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
    PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
    PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties;

    // ---- Core 1_1 commands
    PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
    PFN_vkEnumeratePhysicalDeviceGroups vkEnumeratePhysicalDeviceGroups;
    PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2;
    PFN_vkGetPhysicalDeviceProperties2 vkGetPhysicalDeviceProperties2;
    PFN_vkGetPhysicalDeviceFormatProperties2 vkGetPhysicalDeviceFormatProperties2;
    PFN_vkGetPhysicalDeviceImageFormatProperties2 vkGetPhysicalDeviceImageFormatProperties2;
    PFN_vkGetPhysicalDeviceQueueFamilyProperties2 vkGetPhysicalDeviceQueueFamilyProperties2;
    PFN_vkGetPhysicalDeviceMemoryProperties2 vkGetPhysicalDeviceMemoryProperties2;
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 vkGetPhysicalDeviceSparseImageFormatProperties2;
    PFN_vkGetPhysicalDeviceExternalBufferProperties vkGetPhysicalDeviceExternalBufferProperties;
    PFN_vkGetPhysicalDeviceExternalFenceProperties vkGetPhysicalDeviceExternalFenceProperties;
    PFN_vkGetPhysicalDeviceExternalSemaphoreProperties vkGetPhysicalDeviceExternalSemaphoreProperties;

    // ---- VK_KHR_surface extension commands
    PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;
    PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
    PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
    PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
    PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;

    // ---- VK_KHR_swapchain extension commands
    PFN_vkGetPhysicalDevicePresentRectanglesKHR vkGetPhysicalDevicePresentRectanglesKHR;

    // ---- VK_KHR_display extension commands
    PFN_vkGetPhysicalDeviceDisplayPropertiesKHR vkGetPhysicalDeviceDisplayPropertiesKHR;
    PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
    PFN_vkGetDisplayPlaneSupportedDisplaysKHR vkGetDisplayPlaneSupportedDisplaysKHR;
    PFN_vkGetDisplayModePropertiesKHR vkGetDisplayModePropertiesKHR;
    PFN_vkCreateDisplayModeKHR vkCreateDisplayModeKHR;
    PFN_vkGetDisplayPlaneCapabilitiesKHR vkGetDisplayPlaneCapabilitiesKHR;
    PFN_vkCreateDisplayPlaneSurfaceKHR vkCreateDisplayPlaneSurfaceKHR;

    // ---- VK_KHR_xlib_surface extension commands
#ifdef VK_USE_PLATFORM_XLIB_KHR
    PFN_vkCreateXlibSurfaceKHR vkCreateXlibSurfaceKHR;
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif // VK_USE_PLATFORM_XLIB_KHR

    // ---- VK_KHR_xcb_surface extension commands
#ifdef VK_USE_PLATFORM_XCB_KHR
    PFN_vkCreateXcbSurfaceKHR vkCreateXcbSurfaceKHR;
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR vkGetPhysicalDeviceXcbPresentationSupportKHR;
#endif // VK_USE_PLATFORM_XCB_KHR

    // ---- VK_KHR_wayland_surface extension commands
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    PFN_vkCreateWaylandSurfaceKHR vkCreateWaylandSurfaceKHR;
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR vkGetPhysicalDeviceWaylandPresentationSupportKHR;
#endif // VK_USE_PLATFORM_WAYLAND_KHR

    // ---- VK_KHR_android_surface extension commands
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR;
#endif // VK_USE_PLATFORM_ANDROID_KHR

    // ---- VK_KHR_win32_surface extension commands
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR;
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif // VK_USE_PLATFORM_WIN32_KHR

    // ---- VK_KHR_get_physical_device_properties2 extension commands
    PFN_vkGetPhysicalDeviceFeatures2KHR vkGetPhysicalDeviceFeatures2KHR;
    PFN_vkGetPhysicalDeviceProperties2KHR vkGetPhysicalDeviceProperties2KHR;
    PFN_vkGetPhysicalDeviceFormatProperties2KHR vkGetPhysicalDeviceFormatProperties2KHR;
    PFN_vkGetPhysicalDeviceImageFormatProperties2KHR vkGetPhysicalDeviceImageFormatProperties2KHR;
    PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR vkGetPhysicalDeviceQueueFamilyProperties2KHR;
    PFN_vkGetPhysicalDeviceMemoryProperties2KHR vkGetPhysicalDeviceMemoryProperties2KHR;
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR vkGetPhysicalDeviceSparseImageFormatProperties2KHR;

    // ---- VK_KHR_device_group_creation extension commands
    PFN_vkEnumeratePhysicalDeviceGroupsKHR vkEnumeratePhysicalDeviceGroupsKHR;

    // ---- VK_KHR_external_memory_capabilities extension commands
    PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR vkGetPhysicalDeviceExternalBufferPropertiesKHR;

    // ---- VK_KHR_external_semaphore_capabilities extension commands
    PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;

    // ---- VK_KHR_external_fence_capabilities extension commands
    PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR vkGetPhysicalDeviceExternalFencePropertiesKHR;

    // ---- VK_KHR_get_surface_capabilities2 extension commands
    PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR vkGetPhysicalDeviceSurfaceCapabilities2KHR;
    PFN_vkGetPhysicalDeviceSurfaceFormats2KHR vkGetPhysicalDeviceSurfaceFormats2KHR;

    // ---- VK_KHR_get_display_properties2 extension commands
    PFN_vkGetPhysicalDeviceDisplayProperties2KHR vkGetPhysicalDeviceDisplayProperties2KHR;
    PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
    PFN_vkGetDisplayModeProperties2KHR vkGetDisplayModeProperties2KHR;
    PFN_vkGetDisplayPlaneCapabilities2KHR vkGetDisplayPlaneCapabilities2KHR;

    // ---- VK_EXT_debug_report extension commands
    PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT;
    PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT;
    PFN_vkDebugReportMessageEXT vkDebugReportMessageEXT;

    // ---- VK_GGP_stream_descriptor_surface extension commands
#ifdef VK_USE_PLATFORM_GGP
    PFN_vkCreateStreamDescriptorSurfaceGGP vkCreateStreamDescriptorSurfaceGGP;
#endif // VK_USE_PLATFORM_GGP

    // ---- VK_NV_external_memory_capabilities extension commands
    PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV vkGetPhysicalDeviceExternalImageFormatPropertiesNV;

    // ---- VK_NN_vi_surface extension commands
#ifdef VK_USE_PLATFORM_VI_NN
    PFN_vkCreateViSurfaceNN vkCreateViSurfaceNN;
#endif // VK_USE_PLATFORM_VI_NN

    // ---- VK_NVX_device_generated_commands extension commands
    PFN_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX;

    // ---- VK_EXT_direct_mode_display extension commands
    PFN_vkReleaseDisplayEXT vkReleaseDisplayEXT;

    // ---- VK_EXT_acquire_xlib_display extension commands
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
    PFN_vkAcquireXlibDisplayEXT vkAcquireXlibDisplayEXT;
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
    PFN_vkGetRandROutputDisplayEXT vkGetRandROutputDisplayEXT;
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT

    // ---- VK_EXT_display_surface_counter extension commands
    PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT vkGetPhysicalDeviceSurfaceCapabilities2EXT;

    // ---- VK_MVK_ios_surface extension commands
#ifdef VK_USE_PLATFORM_IOS_MVK
    PFN_vkCreateIOSSurfaceMVK vkCreateIOSSurfaceMVK;
#endif // VK_USE_PLATFORM_IOS_MVK

    // ---- VK_MVK_macos_surface extension commands
#ifdef VK_USE_PLATFORM_MACOS_MVK
    PFN_vkCreateMacOSSurfaceMVK vkCreateMacOSSurfaceMVK;
#endif // VK_USE_PLATFORM_MACOS_MVK

    // ---- VK_EXT_debug_utils extension commands
    PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT;
    PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT;
    PFN_vkSubmitDebugUtilsMessageEXT vkSubmitDebugUtilsMessageEXT;

    // ---- VK_EXT_sample_locations extension commands
    PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT vkGetPhysicalDeviceMultisamplePropertiesEXT;

    // ---- VK_EXT_calibrated_timestamps extension commands
    PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;

    // ---- VK_FUCHSIA_imagepipe_surface extension commands
#ifdef VK_USE_PLATFORM_FUCHSIA
    PFN_vkCreateImagePipeSurfaceFUCHSIA vkCreateImagePipeSurfaceFUCHSIA;
#endif // VK_USE_PLATFORM_FUCHSIA

    // ---- VK_EXT_metal_surface extension commands
#ifdef VK_USE_PLATFORM_METAL_EXT
    PFN_vkCreateMetalSurfaceEXT vkCreateMetalSurfaceEXT;
#endif // VK_USE_PLATFORM_METAL_EXT

    // ---- VK_NV_cooperative_matrix extension commands
    PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV vkGetPhysicalDeviceCooperativeMatrixPropertiesNV;

    // ---- VK_NV_coverage_reduction_mode extension commands
    PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV;

    // ---- VK_EXT_full_screen_exclusive extension commands
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT vkGetPhysicalDeviceSurfacePresentModes2EXT;
#endif // VK_USE_PLATFORM_WIN32_KHR

    // ---- VK_EXT_headless_surface extension commands
    PFN_vkCreateHeadlessSurfaceEXT vkCreateHeadlessSurfaceEXT;
} VkInstanceBindings;
// Device function pointers
typedef struct VkDeviceBindings_ {

    // ---- Core 1_0 commands
    PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
    PFN_vkDestroyDevice vkDestroyDevice;
    PFN_vkGetDeviceQueue vkGetDeviceQueue;
    PFN_vkQueueSubmit vkQueueSubmit;
    PFN_vkQueueWaitIdle vkQueueWaitIdle;
    PFN_vkDeviceWaitIdle vkDeviceWaitIdle;
    PFN_vkAllocateMemory vkAllocateMemory;
    PFN_vkFreeMemory vkFreeMemory;
    PFN_vkMapMemory vkMapMemory;
    PFN_vkUnmapMemory vkUnmapMemory;
    PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges;
    PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges;
    PFN_vkGetDeviceMemoryCommitment vkGetDeviceMemoryCommitment;
    PFN_vkBindBufferMemory vkBindBufferMemory;
    PFN_vkBindImageMemory vkBindImageMemory;
    PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
    PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
    PFN_vkGetImageSparseMemoryRequirements vkGetImageSparseMemoryRequirements;
    PFN_vkQueueBindSparse vkQueueBindSparse;
    PFN_vkCreateFence vkCreateFence;
    PFN_vkDestroyFence vkDestroyFence;
    PFN_vkResetFences vkResetFences;
    PFN_vkGetFenceStatus vkGetFenceStatus;
    PFN_vkWaitForFences vkWaitForFences;
    PFN_vkCreateSemaphore vkCreateSemaphore;
    PFN_vkDestroySemaphore vkDestroySemaphore;
    PFN_vkCreateEvent vkCreateEvent;
    PFN_vkDestroyEvent vkDestroyEvent;
    PFN_vkGetEventStatus vkGetEventStatus;
    PFN_vkSetEvent vkSetEvent;
    PFN_vkResetEvent vkResetEvent;
    PFN_vkCreateQueryPool vkCreateQueryPool;
    PFN_vkDestroyQueryPool vkDestroyQueryPool;
    PFN_vkGetQueryPoolResults vkGetQueryPoolResults;
    PFN_vkCreateBuffer vkCreateBuffer;
    PFN_vkDestroyBuffer vkDestroyBuffer;
    PFN_vkCreateBufferView vkCreateBufferView;
    PFN_vkDestroyBufferView vkDestroyBufferView;
    PFN_vkCreateImage vkCreateImage;
    PFN_vkDestroyImage vkDestroyImage;
    PFN_vkGetImageSubresourceLayout vkGetImageSubresourceLayout;
    PFN_vkCreateImageView vkCreateImageView;
    PFN_vkDestroyImageView vkDestroyImageView;
    PFN_vkCreateShaderModule vkCreateShaderModule;
    PFN_vkDestroyShaderModule vkDestroyShaderModule;
    PFN_vkCreatePipelineCache vkCreatePipelineCache;
    PFN_vkDestroyPipelineCache vkDestroyPipelineCache;
    PFN_vkGetPipelineCacheData vkGetPipelineCacheData;
    PFN_vkMergePipelineCaches vkMergePipelineCaches;
    PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines;
    PFN_vkCreateComputePipelines vkCreateComputePipelines;
    PFN_vkDestroyPipeline vkDestroyPipeline;
    PFN_vkCreatePipelineLayout vkCreatePipelineLayout;
    PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout;
    PFN_vkCreateSampler vkCreateSampler;
    PFN_vkDestroySampler vkDestroySampler;
    PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout;
    PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout;
    PFN_vkCreateDescriptorPool vkCreateDescriptorPool;
    PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool;
    PFN_vkResetDescriptorPool vkResetDescriptorPool;
    PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets;
    PFN_vkFreeDescriptorSets vkFreeDescriptorSets;
    PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets;
    PFN_vkCreateFramebuffer vkCreateFramebuffer;
    PFN_vkDestroyFramebuffer vkDestroyFramebuffer;
    PFN_vkCreateRenderPass vkCreateRenderPass;
    PFN_vkDestroyRenderPass vkDestroyRenderPass;
    PFN_vkGetRenderAreaGranularity vkGetRenderAreaGranularity;
    PFN_vkCreateCommandPool vkCreateCommandPool;
    PFN_vkDestroyCommandPool vkDestroyCommandPool;
    PFN_vkResetCommandPool vkResetCommandPool;
    PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
    PFN_vkFreeCommandBuffers vkFreeCommandBuffers;
    PFN_vkBeginCommandBuffer vkBeginCommandBuffer;
    PFN_vkEndCommandBuffer vkEndCommandBuffer;
    PFN_vkResetCommandBuffer vkResetCommandBuffer;
    PFN_vkCmdBindPipeline vkCmdBindPipeline;
    PFN_vkCmdSetViewport vkCmdSetViewport;
    PFN_vkCmdSetScissor vkCmdSetScissor;
    PFN_vkCmdSetLineWidth vkCmdSetLineWidth;
    PFN_vkCmdSetDepthBias vkCmdSetDepthBias;
    PFN_vkCmdSetBlendConstants vkCmdSetBlendConstants;
    PFN_vkCmdSetDepthBounds vkCmdSetDepthBounds;
    PFN_vkCmdSetStencilCompareMask vkCmdSetStencilCompareMask;
    PFN_vkCmdSetStencilWriteMask vkCmdSetStencilWriteMask;
    PFN_vkCmdSetStencilReference vkCmdSetStencilReference;
    PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets;
    PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer;
    PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers;
    PFN_vkCmdDraw vkCmdDraw;
    PFN_vkCmdDrawIndexed vkCmdDrawIndexed;
    PFN_vkCmdDrawIndirect vkCmdDrawIndirect;
    PFN_vkCmdDrawIndexedIndirect vkCmdDrawIndexedIndirect;
    PFN_vkCmdDispatch vkCmdDispatch;
    PFN_vkCmdDispatchIndirect vkCmdDispatchIndirect;
    PFN_vkCmdCopyBuffer vkCmdCopyBuffer;
    PFN_vkCmdCopyImage vkCmdCopyImage;
    PFN_vkCmdBlitImage vkCmdBlitImage;
    PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage;
    PFN_vkCmdCopyImageToBuffer vkCmdCopyImageToBuffer;
    PFN_vkCmdUpdateBuffer vkCmdUpdateBuffer;
    PFN_vkCmdFillBuffer vkCmdFillBuffer;
    PFN_vkCmdClearColorImage vkCmdClearColorImage;
    PFN_vkCmdClearDepthStencilImage vkCmdClearDepthStencilImage;
    PFN_vkCmdClearAttachments vkCmdClearAttachments;
    PFN_vkCmdResolveImage vkCmdResolveImage;
    PFN_vkCmdSetEvent vkCmdSetEvent;
    PFN_vkCmdResetEvent vkCmdResetEvent;
    PFN_vkCmdWaitEvents vkCmdWaitEvents;
    PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier;
    PFN_vkCmdBeginQuery vkCmdBeginQuery;
    PFN_vkCmdEndQuery vkCmdEndQuery;
    PFN_vkCmdResetQueryPool vkCmdResetQueryPool;
    PFN_vkCmdWriteTimestamp vkCmdWriteTimestamp;
    PFN_vkCmdCopyQueryPoolResults vkCmdCopyQueryPoolResults;
    PFN_vkCmdPushConstants vkCmdPushConstants;
    PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass;
    PFN_vkCmdNextSubpass vkCmdNextSubpass;
    PFN_vkCmdEndRenderPass vkCmdEndRenderPass;
    PFN_vkCmdExecuteCommands vkCmdExecuteCommands;

    // ---- Core 1_1 commands
    PFN_vkBindBufferMemory2 vkBindBufferMemory2;
    PFN_vkBindImageMemory2 vkBindImageMemory2;
    PFN_vkGetDeviceGroupPeerMemoryFeatures vkGetDeviceGroupPeerMemoryFeatures;
    PFN_vkCmdSetDeviceMask vkCmdSetDeviceMask;
    PFN_vkCmdDispatchBase vkCmdDispatchBase;
    PFN_vkGetImageMemoryRequirements2 vkGetImageMemoryRequirements2;
    PFN_vkGetBufferMemoryRequirements2 vkGetBufferMemoryRequirements2;
    PFN_vkGetImageSparseMemoryRequirements2 vkGetImageSparseMemoryRequirements2;
    PFN_vkTrimCommandPool vkTrimCommandPool;
    PFN_vkGetDeviceQueue2 vkGetDeviceQueue2;
    PFN_vkCreateSamplerYcbcrConversion vkCreateSamplerYcbcrConversion;
    PFN_vkDestroySamplerYcbcrConversion vkDestroySamplerYcbcrConversion;
    PFN_vkCreateDescriptorUpdateTemplate vkCreateDescriptorUpdateTemplate;
    PFN_vkDestroyDescriptorUpdateTemplate vkDestroyDescriptorUpdateTemplate;
    PFN_vkUpdateDescriptorSetWithTemplate vkUpdateDescriptorSetWithTemplate;
    PFN_vkGetDescriptorSetLayoutSupport vkGetDescriptorSetLayoutSupport;

    // ---- VK_KHR_swapchain extension commands
    PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
    PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
    PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
    PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
    PFN_vkQueuePresentKHR vkQueuePresentKHR;
    PFN_vkGetDeviceGroupPresentCapabilitiesKHR vkGetDeviceGroupPresentCapabilitiesKHR;
    PFN_vkGetDeviceGroupSurfacePresentModesKHR vkGetDeviceGroupSurfacePresentModesKHR;
    PFN_vkAcquireNextImage2KHR vkAcquireNextImage2KHR;

    // ---- VK_KHR_display_swapchain extension commands
    PFN_vkCreateSharedSwapchainsKHR vkCreateSharedSwapchainsKHR;

    // ---- VK_KHR_device_group extension commands
    PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR vkGetDeviceGroupPeerMemoryFeaturesKHR;
    PFN_vkCmdSetDeviceMaskKHR vkCmdSetDeviceMaskKHR;
    PFN_vkCmdDispatchBaseKHR vkCmdDispatchBaseKHR;

    // ---- VK_KHR_maintenance1 extension commands
    PFN_vkTrimCommandPoolKHR vkTrimCommandPoolKHR;

    // ---- VK_KHR_external_memory_win32 extension commands
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkGetMemoryWin32HandleKHR vkGetMemoryWin32HandleKHR;
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkGetMemoryWin32HandlePropertiesKHR vkGetMemoryWin32HandlePropertiesKHR;
#endif // VK_USE_PLATFORM_WIN32_KHR

    // ---- VK_KHR_external_memory_fd extension commands
    PFN_vkGetMemoryFdKHR vkGetMemoryFdKHR;
    PFN_vkGetMemoryFdPropertiesKHR vkGetMemoryFdPropertiesKHR;

    // ---- VK_KHR_external_semaphore_win32 extension commands
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkImportSemaphoreWin32HandleKHR vkImportSemaphoreWin32HandleKHR;
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkGetSemaphoreWin32HandleKHR vkGetSemaphoreWin32HandleKHR;
#endif // VK_USE_PLATFORM_WIN32_KHR

    // ---- VK_KHR_external_semaphore_fd extension commands
    PFN_vkImportSemaphoreFdKHR vkImportSemaphoreFdKHR;
    PFN_vkGetSemaphoreFdKHR vkGetSemaphoreFdKHR;

    // ---- VK_KHR_push_descriptor extension commands
    PFN_vkCmdPushDescriptorSetKHR vkCmdPushDescriptorSetKHR;
    PFN_vkCmdPushDescriptorSetWithTemplateKHR vkCmdPushDescriptorSetWithTemplateKHR;

    // ---- VK_KHR_descriptor_update_template extension commands
    PFN_vkCreateDescriptorUpdateTemplateKHR vkCreateDescriptorUpdateTemplateKHR;
    PFN_vkDestroyDescriptorUpdateTemplateKHR vkDestroyDescriptorUpdateTemplateKHR;
    PFN_vkUpdateDescriptorSetWithTemplateKHR vkUpdateDescriptorSetWithTemplateKHR;

    // ---- VK_KHR_create_renderpass2 extension commands
    PFN_vkCreateRenderPass2KHR vkCreateRenderPass2KHR;
    PFN_vkCmdBeginRenderPass2KHR vkCmdBeginRenderPass2KHR;
    PFN_vkCmdNextSubpass2KHR vkCmdNextSubpass2KHR;
    PFN_vkCmdEndRenderPass2KHR vkCmdEndRenderPass2KHR;

    // ---- VK_KHR_shared_presentable_image extension commands
    PFN_vkGetSwapchainStatusKHR vkGetSwapchainStatusKHR;

    // ---- VK_KHR_external_fence_win32 extension commands
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkImportFenceWin32HandleKHR vkImportFenceWin32HandleKHR;
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkGetFenceWin32HandleKHR vkGetFenceWin32HandleKHR;
#endif // VK_USE_PLATFORM_WIN32_KHR

    // ---- VK_KHR_external_fence_fd extension commands
    PFN_vkImportFenceFdKHR vkImportFenceFdKHR;
    PFN_vkGetFenceFdKHR vkGetFenceFdKHR;

    // ---- VK_KHR_get_memory_requirements2 extension commands
    PFN_vkGetImageMemoryRequirements2KHR vkGetImageMemoryRequirements2KHR;
    PFN_vkGetBufferMemoryRequirements2KHR vkGetBufferMemoryRequirements2KHR;
    PFN_vkGetImageSparseMemoryRequirements2KHR vkGetImageSparseMemoryRequirements2KHR;

    // ---- VK_KHR_sampler_ycbcr_conversion extension commands
    PFN_vkCreateSamplerYcbcrConversionKHR vkCreateSamplerYcbcrConversionKHR;
    PFN_vkDestroySamplerYcbcrConversionKHR vkDestroySamplerYcbcrConversionKHR;

    // ---- VK_KHR_bind_memory2 extension commands
    PFN_vkBindBufferMemory2KHR vkBindBufferMemory2KHR;
    PFN_vkBindImageMemory2KHR vkBindImageMemory2KHR;

    // ---- VK_KHR_maintenance3 extension commands
    PFN_vkGetDescriptorSetLayoutSupportKHR vkGetDescriptorSetLayoutSupportKHR;

    // ---- VK_KHR_draw_indirect_count extension commands
    PFN_vkCmdDrawIndirectCountKHR vkCmdDrawIndirectCountKHR;
    PFN_vkCmdDrawIndexedIndirectCountKHR vkCmdDrawIndexedIndirectCountKHR;

    // ---- VK_KHR_pipeline_executable_properties extension commands
    PFN_vkGetPipelineExecutablePropertiesKHR vkGetPipelineExecutablePropertiesKHR;
    PFN_vkGetPipelineExecutableStatisticsKHR vkGetPipelineExecutableStatisticsKHR;
    PFN_vkGetPipelineExecutableInternalRepresentationsKHR vkGetPipelineExecutableInternalRepresentationsKHR;

    // ---- VK_EXT_debug_marker extension commands
    PFN_vkDebugMarkerSetObjectTagEXT vkDebugMarkerSetObjectTagEXT;
    PFN_vkDebugMarkerSetObjectNameEXT vkDebugMarkerSetObjectNameEXT;
    PFN_vkCmdDebugMarkerBeginEXT vkCmdDebugMarkerBeginEXT;
    PFN_vkCmdDebugMarkerEndEXT vkCmdDebugMarkerEndEXT;
    PFN_vkCmdDebugMarkerInsertEXT vkCmdDebugMarkerInsertEXT;

    // ---- VK_EXT_transform_feedback extension commands
    PFN_vkCmdBindTransformFeedbackBuffersEXT vkCmdBindTransformFeedbackBuffersEXT;
    PFN_vkCmdBeginTransformFeedbackEXT vkCmdBeginTransformFeedbackEXT;
    PFN_vkCmdEndTransformFeedbackEXT vkCmdEndTransformFeedbackEXT;
    PFN_vkCmdBeginQueryIndexedEXT vkCmdBeginQueryIndexedEXT;
    PFN_vkCmdEndQueryIndexedEXT vkCmdEndQueryIndexedEXT;
    PFN_vkCmdDrawIndirectByteCountEXT vkCmdDrawIndirectByteCountEXT;

    // ---- VK_NVX_image_view_handle extension commands
    PFN_vkGetImageViewHandleNVX vkGetImageViewHandleNVX;

    // ---- VK_AMD_draw_indirect_count extension commands
    PFN_vkCmdDrawIndirectCountAMD vkCmdDrawIndirectCountAMD;
    PFN_vkCmdDrawIndexedIndirectCountAMD vkCmdDrawIndexedIndirectCountAMD;

    // ---- VK_AMD_shader_info extension commands
    PFN_vkGetShaderInfoAMD vkGetShaderInfoAMD;

    // ---- VK_NV_external_memory_win32 extension commands
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkGetMemoryWin32HandleNV vkGetMemoryWin32HandleNV;
#endif // VK_USE_PLATFORM_WIN32_KHR

    // ---- VK_EXT_conditional_rendering extension commands
    PFN_vkCmdBeginConditionalRenderingEXT vkCmdBeginConditionalRenderingEXT;
    PFN_vkCmdEndConditionalRenderingEXT vkCmdEndConditionalRenderingEXT;

    // ---- VK_NVX_device_generated_commands extension commands
    PFN_vkCmdProcessCommandsNVX vkCmdProcessCommandsNVX;
    PFN_vkCmdReserveSpaceForCommandsNVX vkCmdReserveSpaceForCommandsNVX;
    PFN_vkCreateIndirectCommandsLayoutNVX vkCreateIndirectCommandsLayoutNVX;
    PFN_vkDestroyIndirectCommandsLayoutNVX vkDestroyIndirectCommandsLayoutNVX;
    PFN_vkCreateObjectTableNVX vkCreateObjectTableNVX;
    PFN_vkDestroyObjectTableNVX vkDestroyObjectTableNVX;
    PFN_vkRegisterObjectsNVX vkRegisterObjectsNVX;
    PFN_vkUnregisterObjectsNVX vkUnregisterObjectsNVX;

    // ---- VK_NV_clip_space_w_scaling extension commands
    PFN_vkCmdSetViewportWScalingNV vkCmdSetViewportWScalingNV;

    // ---- VK_EXT_display_control extension commands
    PFN_vkDisplayPowerControlEXT vkDisplayPowerControlEXT;
    PFN_vkRegisterDeviceEventEXT vkRegisterDeviceEventEXT;
    PFN_vkRegisterDisplayEventEXT vkRegisterDisplayEventEXT;
    PFN_vkGetSwapchainCounterEXT vkGetSwapchainCounterEXT;

    // ---- VK_GOOGLE_display_timing extension commands
    PFN_vkGetRefreshCycleDurationGOOGLE vkGetRefreshCycleDurationGOOGLE;
    PFN_vkGetPastPresentationTimingGOOGLE vkGetPastPresentationTimingGOOGLE;

    // ---- VK_EXT_discard_rectangles extension commands
    PFN_vkCmdSetDiscardRectangleEXT vkCmdSetDiscardRectangleEXT;

    // ---- VK_EXT_hdr_metadata extension commands
    PFN_vkSetHdrMetadataEXT vkSetHdrMetadataEXT;

    // ---- VK_EXT_debug_utils extension commands
    PFN_vkSetDebugUtilsObjectNameEXT vkSetDebugUtilsObjectNameEXT;
    PFN_vkSetDebugUtilsObjectTagEXT vkSetDebugUtilsObjectTagEXT;
    PFN_vkQueueBeginDebugUtilsLabelEXT vkQueueBeginDebugUtilsLabelEXT;
    PFN_vkQueueEndDebugUtilsLabelEXT vkQueueEndDebugUtilsLabelEXT;
    PFN_vkQueueInsertDebugUtilsLabelEXT vkQueueInsertDebugUtilsLabelEXT;
    PFN_vkCmdBeginDebugUtilsLabelEXT vkCmdBeginDebugUtilsLabelEXT;
    PFN_vkCmdEndDebugUtilsLabelEXT vkCmdEndDebugUtilsLabelEXT;
    PFN_vkCmdInsertDebugUtilsLabelEXT vkCmdInsertDebugUtilsLabelEXT;

    // ---- VK_ANDROID_external_memory_android_hardware_buffer extension commands
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    PFN_vkGetAndroidHardwareBufferPropertiesANDROID vkGetAndroidHardwareBufferPropertiesANDROID;
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    PFN_vkGetMemoryAndroidHardwareBufferANDROID vkGetMemoryAndroidHardwareBufferANDROID;
#endif // VK_USE_PLATFORM_ANDROID_KHR

    // ---- VK_EXT_sample_locations extension commands
    PFN_vkCmdSetSampleLocationsEXT vkCmdSetSampleLocationsEXT;

    // ---- VK_EXT_image_drm_format_modifier extension commands
    PFN_vkGetImageDrmFormatModifierPropertiesEXT vkGetImageDrmFormatModifierPropertiesEXT;

    // ---- VK_EXT_validation_cache extension commands
    PFN_vkCreateValidationCacheEXT vkCreateValidationCacheEXT;
    PFN_vkDestroyValidationCacheEXT vkDestroyValidationCacheEXT;
    PFN_vkMergeValidationCachesEXT vkMergeValidationCachesEXT;
    PFN_vkGetValidationCacheDataEXT vkGetValidationCacheDataEXT;

    // ---- VK_NV_shading_rate_image extension commands
    PFN_vkCmdBindShadingRateImageNV vkCmdBindShadingRateImageNV;
    PFN_vkCmdSetViewportShadingRatePaletteNV vkCmdSetViewportShadingRatePaletteNV;
    PFN_vkCmdSetCoarseSampleOrderNV vkCmdSetCoarseSampleOrderNV;

    // ---- VK_NV_ray_tracing extension commands
    PFN_vkCreateAccelerationStructureNV vkCreateAccelerationStructureNV;
    PFN_vkDestroyAccelerationStructureNV vkDestroyAccelerationStructureNV;
    PFN_vkGetAccelerationStructureMemoryRequirementsNV vkGetAccelerationStructureMemoryRequirementsNV;
    PFN_vkBindAccelerationStructureMemoryNV vkBindAccelerationStructureMemoryNV;
    PFN_vkCmdBuildAccelerationStructureNV vkCmdBuildAccelerationStructureNV;
    PFN_vkCmdCopyAccelerationStructureNV vkCmdCopyAccelerationStructureNV;
    PFN_vkCmdTraceRaysNV vkCmdTraceRaysNV;
    PFN_vkCreateRayTracingPipelinesNV vkCreateRayTracingPipelinesNV;
    PFN_vkGetRayTracingShaderGroupHandlesNV vkGetRayTracingShaderGroupHandlesNV;
    PFN_vkGetAccelerationStructureHandleNV vkGetAccelerationStructureHandleNV;
    PFN_vkCmdWriteAccelerationStructuresPropertiesNV vkCmdWriteAccelerationStructuresPropertiesNV;
    PFN_vkCompileDeferredNV vkCompileDeferredNV;

    // ---- VK_EXT_external_memory_host extension commands
    PFN_vkGetMemoryHostPointerPropertiesEXT vkGetMemoryHostPointerPropertiesEXT;

    // ---- VK_AMD_buffer_marker extension commands
    PFN_vkCmdWriteBufferMarkerAMD vkCmdWriteBufferMarkerAMD;

    // ---- VK_EXT_calibrated_timestamps extension commands
    PFN_vkGetCalibratedTimestampsEXT vkGetCalibratedTimestampsEXT;

    // ---- VK_NV_mesh_shader extension commands
    PFN_vkCmdDrawMeshTasksNV vkCmdDrawMeshTasksNV;
    PFN_vkCmdDrawMeshTasksIndirectNV vkCmdDrawMeshTasksIndirectNV;
    PFN_vkCmdDrawMeshTasksIndirectCountNV vkCmdDrawMeshTasksIndirectCountNV;

    // ---- VK_NV_scissor_exclusive extension commands
    PFN_vkCmdSetExclusiveScissorNV vkCmdSetExclusiveScissorNV;

    // ---- VK_NV_device_diagnostic_checkpoints extension commands
    PFN_vkCmdSetCheckpointNV vkCmdSetCheckpointNV;
    PFN_vkGetQueueCheckpointDataNV vkGetQueueCheckpointDataNV;

    // ---- VK_INTEL_performance_query extension commands
    PFN_vkInitializePerformanceApiINTEL vkInitializePerformanceApiINTEL;
    PFN_vkUninitializePerformanceApiINTEL vkUninitializePerformanceApiINTEL;
    PFN_vkCmdSetPerformanceMarkerINTEL vkCmdSetPerformanceMarkerINTEL;
    PFN_vkCmdSetPerformanceStreamMarkerINTEL vkCmdSetPerformanceStreamMarkerINTEL;
    PFN_vkCmdSetPerformanceOverrideINTEL vkCmdSetPerformanceOverrideINTEL;
    PFN_vkAcquirePerformanceConfigurationINTEL vkAcquirePerformanceConfigurationINTEL;
    PFN_vkReleasePerformanceConfigurationINTEL vkReleasePerformanceConfigurationINTEL;
    PFN_vkQueueSetPerformanceConfigurationINTEL vkQueueSetPerformanceConfigurationINTEL;
    PFN_vkGetPerformanceParameterINTEL vkGetPerformanceParameterINTEL;

    // ---- VK_AMD_display_native_hdr extension commands
    PFN_vkSetLocalDimmingAMD vkSetLocalDimmingAMD;

    // ---- VK_EXT_buffer_device_address extension commands
    PFN_vkGetBufferDeviceAddressEXT vkGetBufferDeviceAddressEXT;

    // ---- VK_EXT_full_screen_exclusive extension commands
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkAcquireFullScreenExclusiveModeEXT vkAcquireFullScreenExclusiveModeEXT;
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkReleaseFullScreenExclusiveModeEXT vkReleaseFullScreenExclusiveModeEXT;
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    PFN_vkGetDeviceGroupSurfacePresentModes2EXT vkGetDeviceGroupSurfacePresentModes2EXT;
#endif // VK_USE_PLATFORM_WIN32_KHR

    // ---- VK_EXT_line_rasterization extension commands
    PFN_vkCmdSetLineStippleEXT vkCmdSetLineStippleEXT;

    // ---- VK_EXT_host_query_reset extension commands
    PFN_vkResetQueryPoolEXT vkResetQueryPoolEXT;
} VkDeviceBindings;

