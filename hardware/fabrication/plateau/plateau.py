#!/usr/bin/python2

import sys
sys.path.insert(0, '..')

import cnc
cnc.init()

cnc.tool_width = 3.175
cnc.step_over = cnc.tool_width / 2
cnc.step_down = cnc.tool_width / 2
cnc.tab_width = 2
cnc.tab_height = 0.5

material_height = 10.000 # mm

cnc.fillcircle((0., 0.), 8.5, depth=8.7)
cnc.circle((0., 0.), 90., depth=material_height+0.1, offset='inside', tab=True)



