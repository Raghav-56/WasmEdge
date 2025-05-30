// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2024 Second State INC

#include "loader/serialize.h"

namespace WasmEdge {
namespace Loader {

// Serialize expression. See "include/loader/serialize.h".
Expect<void>
Serializer::serializeExpression(const AST::Expression &Expr,
                                std::vector<uint8_t> &OutVec) const noexcept {
  // Expression: instr*.
  for (const auto &Instr : Expr.getInstrs()) {
    EXPECTED_TRY(serializeInstruction(Instr, OutVec).map_error([](auto E) {
      spdlog::error(ErrInfo::InfoAST(ASTNodeAttr::Expression));
      return E;
    }));
  }
  return {};
}

} // namespace Loader
} // namespace WasmEdge
