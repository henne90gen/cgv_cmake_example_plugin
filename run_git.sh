#!/bin/bash

CGV_GIT_DIR=$1
PLUGIN_BUILD_DIR=$2
$PLUGIN_BUILD_DIR/lib/cgv_viewer \
  plugin:cg_fltk \
  plugin:crg_stereo_view \
  type\(shader_config\):shader_path=$CGV_GIT_DIR/libs/cgv_gl/glsl \
  plugin:my_plugin
