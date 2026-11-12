#pragma once

#include <vector>

#include <vulkan/vulkan_core.h>

#ifdef __OHOS__
namespace dxvk {

  struct D3D11CpuImage {
    std::vector<uint8_t> data;
    VkDeviceSize rowPitch = 0;
    VkDeviceSize slicePitch = 0;
  };

  /**
   * \brief Decompresses BC texture data at upload time
   *
   * When the Maleoon driver lacks textureCompressionBC support,
   * BC formats are remapped to uncompressed equivalents. This
   * function decompresses the original BC data so the uploaded
   * pixels are correct.
   */
  bool DecodeD3D11BcImage(
          VkFormat                 format,
          VkExtent3D               extent,
    const void*                    source,
          VkDeviceSize             sourceRowPitch,
          VkDeviceSize             sourceSlicePitch,
          D3D11CpuImage&           result);

}  // namespace dxvk
#endif  // __OHOS__
