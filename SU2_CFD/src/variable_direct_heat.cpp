/*!
 * \file variable_direct_heat.cpp
 * \brief Definition of the solution fields.
 * \author F. Palacios, T. Economon
 * \version 6.0.0 "Falcon"
 *
 * The current SU2 release has been coordinated by the
 * SU2 International Developers Society <www.su2devsociety.org>
 * with selected contributions from the open-source community.
 *  - Prof. Juan J. Alonso's group at Stanford University.
 *  - Prof. Piero Colonna's group at Delft University of Technology.
 *  - Prof. Nicolas R. Gauger's group at Kaiserslautern University of Technology.
 *  - Prof. Alberto Guardone's group at Polytechnic University of Milan.
 *  - Prof. Rafael Palacios' group at Imperial College London.
 *  - Prof. Edwin van der Weide's group at the University of Twente.
 *  - Prof. Vincent Terrapon's group at the University of Liege.
 *
 * Copyright 2012-2018, Francisco D. Palacios, Thomas D. Economon,
 *                      Tim Albring, and the SU2 contributors.
 *
 * SU2 is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * SU2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with SU2. If not, see <http://www.gnu.org/licenses/>.
 */

#include "../include/variable_structure.hpp"

CHeatVariable::CHeatVariable(void) : CVariable() {
  
  /*--- Array initialization ---*/
  Solution_Direct = NULL;
  
}

CHeatVariable::CHeatVariable(su2double *val_heat, unsigned short val_nDim, unsigned short val_nvar, CConfig *config)
: CVariable(val_nDim, val_nvar, config) {
  unsigned short iVar;
  
  /*--- Array initialization ---*/
  Solution_Direct = NULL;
  
  /*--- Allocate residual structures ---*/
  Residual_Sum = new su2double [nVar]; Residual_Old = new su2double [nVar];
  
  /*--- Allocate direct solution container for adjoint problem ---*/
  Solution_Direct = new su2double[nVar];
  
  /*--- Allocate aux gradient vector ---*/
  Grad_AuxVar = new su2double [nDim];
  
  /*--- Initialization of variables ---*/
  for (iVar = 0; iVar < nVar; iVar++) {
    Solution[iVar] = val_heat[iVar];
    Solution_Old[iVar] = val_heat[iVar];
    Solution_Direct[iVar] = 0.0;
  }
  
}

CHeatVariable::~CHeatVariable(void) {
  
  if (Solution_Direct != NULL) delete [] Solution_Direct;
  
}
