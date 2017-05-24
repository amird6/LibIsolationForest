//	MIT License
//
//  Copyright © 2017 Michael J Simms. All rights reserved.
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in all
//	copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//	SOFTWARE.

#include "IsolationForest.h"
#include <stdlib.h>

using namespace IsolationForest;

int main(int argc, const char * argv[])
{
	Forest forest(10, 10);

	srand((unsigned int)time(NULL));

	// Training samples.
	for (size_t i = 0; i < 10; ++i)
	{
		FeaturePtrList features;
		Sample sample("");

		uint32_t x = 0.3 * (rand() % 100);
		uint32_t y = 0.3 * (rand() % 100);

		features.push_back(new Feature("x", x));
		features.push_back(new Feature("y", y));

		sample.AddFeatures(features);
		forest.AddSample(sample);
	}

	forest.Create();

	// Test samples (similar to training samples).
	for (size_t i = 0; i < 10; ++i)
	{
		FeaturePtrList features;
		Sample sample("");

		uint32_t x = 0.3 * (rand() % 100);
		uint32_t y = 0.3 * (rand() % 100);

		features.push_back(new Feature("x", x));
		features.push_back(new Feature("y", y));

		sample.AddFeatures(features);
	}

	// Outlier samples (different from training samples).
	for (size_t i = 0; i < 10; ++i)
	{
		std::vector<FeaturePtr> outliers;

		uint32_t x = 25.0 + (0.5 * (rand() % 50));
		uint32_t y = 25.0 + (0.5 * (rand() % 50));

		outliers.push_back(new Feature("x", x));
		outliers.push_back(new Feature("y", y));
	}

	return 0;
}
