//===-- llvm/Target/TargetAsmInfo.cpp - Target Assembly Info --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "llvm/Target/TargetAsmInfo.h"
#include "llvm/Target/TargetData.h"
#include "llvm/Target/TargetLowering.h"
#include "llvm/Target/TargetLoweringObjectFile.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetRegisterInfo.h"
using namespace llvm;

TargetAsmInfo::TargetAsmInfo(const TargetMachine &TM) {
  TLOF = &TM.getTargetLowering()->getObjFileLowering();
  TFI = TM.getFrameLowering();
  TRI = TM.getRegisterInfo();
  TFI->getInitialFrameState(InitialFrameState);
}
