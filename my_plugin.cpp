#include "my_plugin.h"

my_plugin::my_plugin() {
  set_name("my_plugin");
}

void my_plugin::stream_help(std::ostream &os) {
    os << "Generates a default background for 3D visualizations in virtual reality" << std::endl;
}

bool my_plugin::init(cgv::render::context &ctx) {
    return true;
}

void my_plugin::clear(cgv::render::context &ctx) {
}

void my_plugin::init_frame(cgv::render::context &ctx) { drawable::init_frame(ctx); }

void my_plugin::draw(cgv::render::context &ctx) {
}

void my_plugin::finish_draw(cgv::render::context &ctx) { drawable::finish_draw(ctx); }

void my_plugin::create_gui() {}

bool my_plugin::handle(cgv::gui::event &e) { return false; }

cgv::base::object_registration<my_plugin> my_plugin_reg("my_plugin"); // NOLINT(cert-err58-cpp)
