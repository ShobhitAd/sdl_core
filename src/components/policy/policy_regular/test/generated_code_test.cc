/* Copyright (c) 2013, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <fstream>

#include "gtest/gtest.h"

#include "json/reader.h"
#include "json/value.h"
#include "policy/policy_table/enums.h"
#include "policy/policy_table/types.h"
#include "rpc_base/gtest_support.h"

using rpc::policy_table_interface_base::Table;

namespace test {
namespace components {
namespace policy_test {

TEST(PolicyGeneratedCodeTest, TestValidPTPreloadJsonIsValid) {
  std::ifstream json_file("sdl_preloaded_pt.json");
  ASSERT_TRUE(json_file.is_open());
  Json::Value valid_table;
  Json::CharReaderBuilder reader_builder;
  ASSERT_TRUE(
      Json::parseFromStream(reader_builder, json_file, &valid_table, nullptr));
  Table table(&valid_table);
  table.SetPolicyTableType(rpc::policy_table_interface_base::PT_PRELOADED);
  ASSERT_RPCTYPE_VALID(table);
}

// cppcheck-suppress syntaxError
TEST(PolicyGeneratedCodeTest, TestValidPTUpdateJsonIsValid) {
  std::ifstream json_file("valid_sdl_pt_update.json");
  ASSERT_TRUE(json_file.is_open());
  Json::Value valid_table;
  Json::CharReaderBuilder reader_builder;
  ASSERT_TRUE(
      Json::parseFromStream(reader_builder, json_file, &valid_table, nullptr));
  Table table(&valid_table);
  table.SetPolicyTableType(rpc::policy_table_interface_base::PT_UPDATE);
  ASSERT_RPCTYPE_VALID(table);
}

}  // namespace policy_test
}  // namespace components
}  // namespace test
