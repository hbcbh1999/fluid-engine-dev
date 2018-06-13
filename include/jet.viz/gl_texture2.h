// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_JET_VIZ_GL_TEXTURE2_H_
#define INCLUDE_JET_VIZ_GL_TEXTURE2_H_

#ifdef JET_USE_GL

#include <jet.viz/gl_texture.h>
#include <jet.viz/texture2.h>
#include <jet/macros.h>

namespace jet {
namespace viz {

//! 2-D OpenGL texture representation.
class GLTexture2 final : public Texture2, public GLTexture {
 public:
    //! Constructs an empty texture.
    GLTexture2();

    //! Destructor.
    virtual ~GLTexture2();

    //! Updates current texture with given 32-bit color data.
    void update(const Color* data) override;

    //! Updates current texture with given 8-bit color data.
    void update(const ByteColor* data) override;

 private:
    Size2 _size;

    void onClear() override;

    void onSetTexture(const ConstArrayView2<Color>& data) override;

    void onSetTexture(const ConstArrayView2<ByteColor>& data) override;

    void onBind(Renderer* renderer, unsigned int slotId) override;

    void onSamplingModeChanged(const TextureSamplingMode& mode) override;
};

}  // namespace viz
}  // namespace jet

#endif  // JET_USE_GL

#endif  // INCLUDE_JET_VIZ_GL_TEXTURE2_H_
