# blender script to extract the true pose, has to be run in blender console

robot = bpy.data.objects['Robot']
#robot = bpy.data.objects['Camera']
for i in range(16):
    bpy.context.scene.frame_set(i)
    fname = str(i).rjust(4, '0') + '.png'
    mat_str = str(robot.matrix_world)[6:].replace('\n', '')
    #mat_str = str(robot.matrix_world.translation_part())
    print(fname + ' ' + mat_str)
