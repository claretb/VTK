set(Module_SRCS
  vtkExporter.cxx
  vtkIVExporter.cxx
  vtkJSONDataSetWriter.cxx
  vtkJSONSceneExporter.cxx
  vtkOBJExporter.cxx
  vtkOOGLExporter.cxx
  vtkPOVExporter.cxx
  vtkRIBExporter.cxx
  vtkRIBLight.cxx
  vtkRIBProperty.cxx
  vtkSingleVTPExporter.cxx
  vtkVRMLExporter.cxx
  vtkX3D.cxx
  vtkX3DExporter.cxx
  vtkX3DExporterFIWriter.cxx
  vtkX3DExporterWriter.cxx
  vtkX3DExporterXMLWriter.cxx
  )
if(NOT EMSCRIPTEN AND NOT VTK_OPENGL_USE_GLES)
  list(APPEND Module_SRCS
    vtkGL2PSExporter.cxx
    vtkSVGContextDevice2D.cxx
    vtkGLTFExporter.cxx
    vtkSVGExporter.cxx
    )
endif()

vtk_module_library(vtkIOExport ${Module_SRCS})
if(NOT EMSCRIPTEN AND NOT VTK_OPENGL_USE_GLES)
  include(vtkOpenGL)
  vtk_opengl_link(vtkIOExport)
endif()
