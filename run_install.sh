#!/bin/bash

CGV_INSTALL_DIR=$1
PLUGIN_BUILD_DIR=$2
$CGV_INSTALL_DIR/lib/cgv_viewer \
  plugin:cg_fltk \
  plugin:crg_stereo_view \
  type\(shader_config\):shader_path=$CGV_INSTALL_DIR/include/cgv-libs/cgv_gl/glsl \
  plugin:$PLUGIN_BUILD_DIR/libmy_plugin.so
