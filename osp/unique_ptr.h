// 
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd. 
// 
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef _UNIQUE_PTR_H_
#define _UNIQUE_PTR_H_

#if __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)

#include <memory>

#else

#include <unique_ptr.hpp>

namespace std
{

using boost::unique_ptr;
using boost::default_delete;
using boost::move;
using boost::forward;
using boost::swap;

}

#endif // __cplusplus || EXPERIMENTAL

#endif // _UNIQUE_PTR_H_
