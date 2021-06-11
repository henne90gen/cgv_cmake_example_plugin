#pragma once

#include <cgv/base/node.h>
#include <cgv/gui/event_handler.h>
#include <cgv/gui/provider.h>
#include <cgv/render/drawable.h>
#include <cgv/render/frame_buffer.h>
#include <cgv/render/shader_program.h>

#include <GL/glew.h>
#include <nlohmann/json.hpp>

class my_plugin : public cgv::base::node,
               public cgv::render::drawable,
               public cgv::gui::event_handler,
               public cgv::gui::provider {
  public:
    my_plugin();

    void stream_help(std::ostream &os) override;
    bool handle(cgv::gui::event &e) override;
    bool init(cgv::render::context &ctx) override;
    void clear(cgv::render::context &ctx) override;
    void init_frame(cgv::render::context &ctx) override;
    void draw(cgv::render::context &ctx) override;
    void finish_draw(cgv::render::context &ctx) override;
    void create_gui() override;
};
