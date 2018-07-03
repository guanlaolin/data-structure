/*
 *   Copyright 2018 guanlaolin
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#include <stdio.h>

int seq_search_normal(int *data, int n, int key) 
{
    if (NULL == data) {
        return 0;
    }

    int i = 0;

    for (i = 1; i < n; i++) {
        if (key == data[i]) {
            return i;
        }
    }

    return 0;
}

int seq_search_with_guard(int *data, int n, int key)
{
    if (NULL == data) {
        return 0;
    }

    int i = n;
    data[0] = key;

    while (data[i] != key)
    {
        i--;
    }

    return i;
}

int bin_search(int *data, int n, int key)
{
    if (NULL == data) {
        return 0;
    }

    int low = 1;
    int high = n; 
    int mid = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (data[mid] > key) {
            high = mid - 1;
        } else if (data[mid] < key) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return 0;
}

int int_search(int *data, int n, int key)
{
    if (NULL == data) {
        return 0;
    }

    int low = 1;
    int high = n;
    int mid = 0;

    while (low <= high) {
        mid = low + (high + low) * (key - data[low]) / (data[high] - data[low]);

        if (data[mid] > key) {
            high = mid - 1;
        } else if (data[mid] < key) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return 0;
}
