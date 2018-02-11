/* =============================================================
The MIT License (MIT)

Copyright (c) 2015 Carlo Meroni

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
================================================================= */

////////////////////////////////////////////////////////////
///	HEADER
////////////////////////////////////////////////////////////
#ifndef BRAIN_H
#define BRAIN_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct neuron neuron;
typedef struct brain brain;

////////////////////////////////////////////////////////////
///	NEURON
////////////////////////////////////////////////////////////
typedef struct neuron
{
	brain* b;
	long id;
	long* links;
	int links_count;
	int links_capacity;
	int* weights;
	float state;
	float nextstate;
	int fired;
} neuron;

////////////////////////////////////////////////////////////
/// \brief	Initialize neuron	
///
////////////////////////////////////////////////////////////
neuron* neuron_init(brain* b, long id);

////////////////////////////////////////////////////////////
/// \brief	Free neuron	
///
////////////////////////////////////////////////////////////
void neuron_free(neuron* n);

////////////////////////////////////////////////////////////
/// \brief	Link two neurons	
///
////////////////////////////////////////////////////////////
void neuron_link(neuron* n, neuron* other, int weight);

////////////////////////////////////////////////////////////
/// \brief	Unlink a neuron from id
///
////////////////////////////////////////////////////////////
void neuron_unlink(neuron* n, long other_id);

////////////////////////////////////////////////////////////
/// \brief	Update neuron states
///
////////////////////////////////////////////////////////////
void neuron_update(neuron* n);

////////////////////////////////////////////////////////////
/// \brief	Fire!	
///
////////////////////////////////////////////////////////////
void neuron_fire(neuron* n);

////////////////////////////////////////////////////////////
/// \brief	Check if the neuron fired	
///
////////////////////////////////////////////////////////////
int neuron_fired(neuron* n);


////////////////////////////////////////////////////////////
///	BRAIN
////////////////////////////////////////////////////////////
typedef struct brain
{
	neuron** neurons;
	int neurons_count;
} brain;

////////////////////////////////////////////////////////////
/// \brief	Initialize brain	
///
////////////////////////////////////////////////////////////
brain* brain_init();

////////////////////////////////////////////////////////////
/// \brief	Free brain	
///
////////////////////////////////////////////////////////////
void brain_free(brain* b);

////////////////////////////////////////////////////////////
/// \brief	Allocate in the brain N neurons
///
////////////////////////////////////////////////////////////
void brain_makeneurons(brain* b, int neurons_count);

////////////////////////////////////////////////////////////
/// \brief	Update neurons states	
///
////////////////////////////////////////////////////////////
void brain_update(brain* b);

#ifdef __cplusplus
} //EXTERN C
#endif

#endif //BRAIN_H
