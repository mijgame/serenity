/*
 * Copyright (c) 2020, Itamar S. <itamar8910@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Expression.h"

#include <AK/Format.h>
#include <AK/MemoryStream.h>
#include <sys/arch/regs.h>

namespace Debug::Dwarf::Expression {

Value evaluate(ReadonlyBytes bytes, [[maybe_unused]] PtraceRegisters const& regs)
{
    InputMemoryStream stream(bytes);

    while (!stream.eof()) {
        u8 opcode = 0;
        stream >> opcode;

        switch (static_cast<Operations>(opcode)) {

        default:
            dbgln("DWARF expr addr: {:p}", bytes.data());
            dbgln("unsupported opcode: {}", opcode);
            VERIFY_NOT_REACHED();
        }
    }
    VERIFY_NOT_REACHED();
}

}
