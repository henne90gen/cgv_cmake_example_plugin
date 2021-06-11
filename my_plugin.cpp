#include "my_plugin.h"

#include <cgv_gl/box_renderer.h>
#include <random>

my_plugin::my_plugin() { set_name("my_plugin"); }

void my_plugin::stream_help(std::ostream &os) {
  os << "Shows how to use the CGV framework with CMake" << std::endl;
}

bool my_plugin::init(cgv::render::context &ctx) {
  auto &box_renderer = cgv::render::ref_box_renderer(ctx, 1);
  if (!box_renderer.init(ctx)) {
    return false;
  }
  return true;
}

void my_plugin::clear(cgv::render::context &ctx) {
  cgv::render::ref_box_renderer(ctx, -1);
}

void my_plugin::init_frame(cgv::render::context &ctx) {
  drawable::init_frame(ctx);
}

void my_plugin::draw(cgv::render::context &ctx) {
  std::vector<vec3> box_positions = {};
  std::mt19937 generator(1337);
  const float range_from = 0.0;
  const float range_to = 4.0;
  std::uniform_real_distribution<float> distribution(range_from, range_to);

  for (int i = 0; i < 100; i++) {
    float x = distribution(generator);
    float y = distribution(generator);
    float z = distribution(generator);
    box_positions.emplace_back(x, y, z);
  }

  auto &box_renderer = cgv::render::ref_box_renderer(ctx, 1);
  auto box_style = cgv::render::box_render_style();
  //  box_style.default_extent = vec3(0.2);
  box_renderer.set_render_style(box_style);
  box_renderer.set_position_array(ctx, box_positions);
  box_renderer.render(ctx, 0, box_positions.size());
}

void my_plugin::finish_draw(cgv::render::context &ctx) {
  drawable::finish_draw(ctx);
}

void my_plugin::create_gui() {}

bool my_plugin::handle(cgv::gui::event &e) { return false; }

cgv::base::object_registration<my_plugin>
    my_plugin_reg("my_plugin"); // NOLINT(cert-err58-cpp)
