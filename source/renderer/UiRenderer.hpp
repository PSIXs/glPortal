#ifndef UIRENDERER_HPP
#define UIRENDERER_HPP

#include <memory>
#include <string>

#include <radix/core/math/Vector3f.hpp>

namespace radix {
  struct RenderContext;
  class Viewport;
  class Camera;
  class Renderer;
}

namespace glPortal {

class World;
class Screen;

class UiRenderer {
public:
  UiRenderer(World& w, radix::Renderer& ren);

  void render();
  void initCamera();

  void renderImage(radix::Vector3f position, radix::Vector3f scale, std::string path);

  static void renderScreen(radix::RenderContext &rc, World &world, Screen &scr);

private:
  World &world;
  radix::Renderer &renderer;
  std::unique_ptr<radix::Camera> camera;
  std::unique_ptr<radix::RenderContext> renderContext;
  int viewportWidth, viewportHeight;
};

} /* namespace glPortal */

#endif /* UIRENDERER_HPP */
