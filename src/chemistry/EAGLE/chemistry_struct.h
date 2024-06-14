/*******************************************************************************
 * This file is part of SWIFT.
 * Copyright (c) 2016 Matthieu Schaller (schaller@strw.leidenuniv.nl)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/
#ifndef SWIFT_CHEMISTRY_STRUCT_EAGLE_H
#define SWIFT_CHEMISTRY_STRUCT_EAGLE_H

#include <config.h>

/**
 * @brief The individual elements traced in the EAGLE model.
 */
/* SAK added chemistry elements */
enum chemistry_element {
chemistry_element_Hydrogen = 0,
chemistry_element_Helium,
chemistry_element_Lithium,
chemistry_element_Carbon,
chemistry_element_Nitrogen,
chemistry_element_Oxygen,
chemistry_element_Neon,
chemistry_element_Sodium,
chemistry_element_Magnesium,
chemistry_element_Aluminum,
chemistry_element_Silicon,
chemistry_element_Potassium,
chemistry_element_Calcium,
chemistry_element_Scandium,
chemistry_element_Titanium,
chemistry_element_Vanadium,
chemistry_element_Chromium,
chemistry_element_Manganese,
chemistry_element_Iron,
chemistry_element_Cobalt,
chemistry_element_Nickel,
chemistry_element_Copper,
chemistry_element_Zinc,
chemistry_element_Rubidium,
chemistry_element_Strontium,
chemistry_element_Yttrium,
chemistry_element_Zirconium,
chemistry_element_Molybdenum,
chemistry_element_Ruthenium,
chemistry_element_Barium,
chemistry_element_Lanthanum,
chemistry_element_Cerium,
chemistry_element_Neodymium,
chemistry_element_Samarium,
chemistry_element_Europium,
  chemistry_element_count
};

/**
 * @brief Global chemical abundance information in the EAGLE model.
 */
struct chemistry_global_data {

  /*! Fraction of the particle mass in given elements at the start of the run */
  float initial_metal_mass_fraction[chemistry_element_count];

  /*! Fraction of the particle mass in *all* metals at the start of the run */
  float initial_metal_mass_fraction_total;
};

/**
 * @brief Chemical abundances traced by the #part in the EAGLE model.
 */
struct chemistry_part_data {

  /*! Fraction of the particle mass in a given element */
  float metal_mass_fraction[chemistry_element_count];

  /*! Fraction of the particle mass in *all* metals */
  float metal_mass_fraction_total;

#ifdef HYDRO_DOES_MASS_FLUX
  /*! Mass fluxes of the metals in a given element */
  float metal_mass_fluxes[chemistry_element_count];

  /*! Mass flux in *all* metals */
  float metal_mass_flux_total;
#endif

  /*! Smoothed fraction of the particle mass in a given element */
  float smoothed_metal_mass_fraction[chemistry_element_count];

  /*! Smoothed fraction of the particle mass in *all* metals */
  float smoothed_metal_mass_fraction_total;

  /*! Mass coming from SNIa */
  float mass_from_SNIa;

  /*! Fraction of total gas mass in metals coming from SNIa */
  float metal_mass_fraction_from_SNIa;

  /*! Mass coming from AGB */
  float mass_from_AGB;

  /*! Fraction of total gas mass in metals coming from AGB */
  float metal_mass_fraction_from_AGB;

  /*! Mass coming from SNII */
  float mass_from_SNII;

  /*! Fraction of total gas mass in metals coming from SNII */
  float metal_mass_fraction_from_SNII;

  /*! Fraction of total gas mass in Iron coming from SNIa */
  float iron_mass_fraction_from_SNIa;

  /*! Smoothed fraction of total gas mass in Iron coming from SNIa */
  float smoothed_iron_mass_fraction_from_SNIa;
};

#define chemistry_spart_data chemistry_part_data

/**
 * @brief Chemical abundances traced by the #bpart in the EAGLE model.
 */
struct chemistry_bpart_data {

  /*! Mass in a given element */
  float metal_mass[chemistry_element_count];

  /*! Mass in *all* metals */
  float metal_mass_total;

  /*! Mass coming from SNIa */
  float mass_from_SNIa;

  /*! Mass coming from AGB */
  float mass_from_AGB;

  /*! Mass coming from SNII */
  float mass_from_SNII;

  /*! Metal mass coming from SNIa */
  float metal_mass_from_SNIa;

  /*! Metal mass coming from AGB */
  float metal_mass_from_AGB;

  /*! Metal mass coming from SNII */
  float metal_mass_from_SNII;

  /*! Iron mass coming from SNIa */
  float iron_mass_from_SNIa;

  /*! Metallicity of converted part. */
  float formation_metallicity;

  /*! Smoothed metallicity of converted part. */
  float smoothed_formation_metallicity;
};

/**
 * @brief Chemical abundances traced by the #sink in the EAGLE model.
 *
 * Nothing here.
 */
struct chemistry_sink_data {};

#endif /* SWIFT_CHEMISTRY_STRUCT_EAGLE_H */
