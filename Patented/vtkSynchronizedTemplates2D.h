/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkSynchronizedTemplates2D.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.


     THIS CLASS IS PATENT PENDING.

     Application of this software for commercial purposes requires 
     a license grant from Kitware. Contact:
         Ken Martin
         Kitware
         28 Corporate Drive Suite 204,
         Clifton Park, NY 12065
         Phone:1-518-371-3971 
     for more information.

=========================================================================*/
// .NAME vtkSynchronizedTemplates2D - generate isoline(s) from a structured points set
// .SECTION Description
// vtkSynchronizedTemplates2D is a 2D implementation of the synchronized 
// template algorithm. Note that vtkContourFilter will automatically
// use this class when appropriate if vtk was built with patents.

// .SECTION Caveats
// This filter is specialized to 2D images.

// .SECTION See Also
// vtkContourFilter vtkSynchronizedTemplates3D

#ifndef __vtkSynchronizedTemplates2D_h
#define __vtkSynchronizedTemplates2D_h

#include "vtkPolyDataAlgorithm.h"

#include "vtkContourValues.h" // Needed for direct access to ContourValues

class vtkImageData;
class vtkKitwareContourFilter;

class VTK_PATENTED_EXPORT vtkSynchronizedTemplates2D : public vtkPolyDataAlgorithm
{
public:
  static vtkSynchronizedTemplates2D *New();
  vtkTypeRevisionMacro(vtkSynchronizedTemplates2D,vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Because we delegate to vtkContourValues
  unsigned long int GetMTime();

  // Description:
  // Set a particular contour value at contour number i. The index i ranges 
  // between 0<=i<NumberOfContours.
  void SetValue(int i, double value) {this->ContourValues->SetValue(i,value);}

  // Description:
  // Get the ith contour value.
  double GetValue(int i) {return this->ContourValues->GetValue(i);}

  // Description:
  // Get a pointer to an array of contour values. There will be
  // GetNumberOfContours() values in the list.
  double *GetValues() {return this->ContourValues->GetValues();}

  // Description:
  // Fill a supplied list with contour values. There will be
  // GetNumberOfContours() values in the list. Make sure you allocate
  // enough memory to hold the list.
  void GetValues(double *contourValues) {
    this->ContourValues->GetValues(contourValues);}

  // Description:
  // Set the number of contours to place into the list. You only really
  // need to use this method to reduce list size. The method SetValue()
  // will automatically increase list size as needed.
  void SetNumberOfContours(int number) {
    this->ContourValues->SetNumberOfContours(number);}

  // Description:
  // Get the number of contours in the list of contour values.
  int GetNumberOfContours() {
    return this->ContourValues->GetNumberOfContours();}

  // Description:
  // Generate numContours equally spaced contour values between specified
  // range. Contour values will include min/max range values.
  void GenerateValues(int numContours, double range[2]) {
    this->ContourValues->GenerateValues(numContours, range);}

  // Description:
  // Generate numContours equally spaced contour values between specified
  // range. Contour values will include min/max range values.
  void GenerateValues(int numContours, double rangeStart, double rangeEnd)
    {this->ContourValues->GenerateValues(numContours, rangeStart, rangeEnd);}

  // Description:
  // Option to set the point scalars of the output.  The scalars will be the 
  // iso value of course.  By default this flag is on.
  vtkSetMacro(ComputeScalars,int);
  vtkGetMacro(ComputeScalars,int);
  vtkBooleanMacro(ComputeScalars,int);

  // Description:
  // If you want to contour by an arbitrary array, then set its name here.
  // By default this in NULL and the filter will use the active scalar array.
  vtkGetStringMacro(InputScalarsSelection);
  void SelectInputScalars(const char *fieldName) 
    {this->SetInputScalarsSelection(fieldName);}
  
  // Description:
  // Set/get which component of the scalar array to contour on; defaults to 0.
  vtkSetMacro(ArrayComponent, int);
  vtkGetMacro(ArrayComponent, int);
  
protected:
  vtkSynchronizedTemplates2D();
  ~vtkSynchronizedTemplates2D();

  int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);
  vtkContourValues *ContourValues;

  int ComputeScalars;
  int ArrayComponent;

  virtual int FillInputPortInformation(int, vtkInformation*);
  
  char *InputScalarsSelection;
  vtkSetStringMacro(InputScalarsSelection);

private:
  //BTX
  friend class VTK_PATENTED_EXPORT vtkKitwareContourFilter;
  //ETX
private:
  vtkSynchronizedTemplates2D(const vtkSynchronizedTemplates2D&);  // Not implemented.
  void operator=(const vtkSynchronizedTemplates2D&);  // Not implemented.
};


#endif

