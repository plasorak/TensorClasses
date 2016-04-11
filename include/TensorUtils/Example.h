#ifndef EXAMPLE_H
#define EXAMPLE_H

// // (c) Copyright 2016 Pierre Jean Joseph Lasorak

// 

// This software is distributed under the terms of the GNU General Public

// Licence version 3 (GPL Version 3), copied verbatim in the file "LICENCE".



/**
 * @file
 * @author Pierre Jean Joseph Lasorak
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * An example class for the HSF
 *
 *
 */

namespace TensorUtils {

  class Example {
  public:
    /// Default constructor
    Example();

    /// Default destructor
    virtual ~Example();

    /**
     * Constructor from a given number
     *
     * @param number initial value
     */
    Example(int number);

    /**
     * Get current value
     */
    int get() const;

    /**
     * Set new value
     *
     * @param number new value
     *
     */
     void set(int number);

  private:
    /// Internally stored number
    int m_number;
  };
}

#endif
