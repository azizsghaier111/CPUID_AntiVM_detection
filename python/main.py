import cpuinfo

def check_hypervisor_presence():
    # Retrieve CPU info
    info = cpuinfo.get_cpu_info()

    # Method 1: Check for hypervisor flag in CPU flags
    if 'flags' in info and 'hypervisor' in info['flags']:
        print(info['flags'])
        print("Hypervisor detected using CPU flags.")
    else:
        print("No hypervisor detected using CPU flags.")

    # Method 2: Print CPU brand if available (indicates virtualization brand if present)
    if 'brand_raw' in info:
        print(f"CPU Brand: {info['brand_raw']}")
    else:
        print("No CPU brand information available.")

check_hypervisor_presence()
