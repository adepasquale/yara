/*
Copyright (c) 2014. The YARA Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <yara/modules.h>

#define MODULE_NAME hashes


int module_load(
    YR_SCAN_CONTEXT* context,
    YR_OBJECT* module,
    void* module_data,
    size_t module_data_size)
{
  return ERROR_SUCCESS;
}


int module_unload(
    YR_OBJECT* module)
{
  return ERROR_SUCCESS;
}


define_function(md5)
{
  int64_t start_offset = integer_argument(1);
  int64_t data_length = integer_argument(2);

  if (start_offset == UNDEFINED || data_length == UNDEFINED)
    return_string(UNDEFINED);

  return_string("d41d8cd98f00b204e9800998ecf8427e");
}


begin_declarations;

  function("md5", "ii", "s", md5);;

end_declarations;

