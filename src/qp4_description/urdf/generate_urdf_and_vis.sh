#!/bin/bash

rosrun xacro xacro.py `rospack find qp4_description`/urdf/qp4.xacro -o `rospack find qp4_description`/urdf/qp4.urdf &&
check_urdf `rospack find qp4_description`/urdf/qp4.urdf &&
urdf_to_graphiz `rospack find qp4_description`/urdf/qp4.urdf
