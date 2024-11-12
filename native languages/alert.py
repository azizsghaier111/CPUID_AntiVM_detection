from ghidra.program.model.listing import Listing
from ghidra.program.model.listing import Instruction
from ghidra.util.task import ConsoleTaskMonitor

def detect_cpuid_instructions():
    print("here I started the detection")
    listing = currentProgram.getListing()
    
    # Iterate over all instructions in the current program
    for instruction in listing.getInstructions(True):
        if instruction.getMnemonicString() == "CPUID":
            addr = instruction.getAddress()
            print("CPUID instruction found at address: {}".format(addr))
            popup("CPUID instruction detected at address: {}".format(addr))

detect_cpuid_instructions()
