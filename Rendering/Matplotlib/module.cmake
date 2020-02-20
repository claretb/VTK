if(ANDROID OR APPLE_IOS OR EMSCRIPTEN OR VTK_OPENGL_USE_GLES)
  set(gl2ps_depends)
elseif(VTK_RENDERING_BACKEND STREQUAL "OpenGL2")
  set(gl2ps_depends vtkRenderingGL2PSOpenGL2 vtkIOExportOpenGL2)
endif()
vtk_module(vtkRenderingMatplotlib
  IMPLEMENTS
    vtkRenderingFreeType
  TEST_DEPENDS
    vtkCommonColor
    vtkInteractionImage
    vtkInteractionWidgets
    vtkIOGeometry
    vtkIOParallel
    vtkTestingRendering
    vtkInteractionStyle
    vtkRenderingContextOpenGL2
    vtkRenderingOpenGL2
    vtkViewsContext2D
    ${gl2ps_depends}
  DEPENDS
    vtkPythonInterpreter
    vtkRenderingFreeType
  PRIVATE_DEPENDS
    vtkCommonCore
    vtkCommonDataModel
    vtkCommonTransforms
    vtkImagingCore
    vtkPython
    vtkRenderingCore
    vtkWrappingPythonCore
  )
