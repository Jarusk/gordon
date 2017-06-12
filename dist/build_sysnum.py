#! /bin/env python3

import urllib.request

REPO = "https://raw.githubusercontent.com/torvalds/linux/master"
SYSCALL_32 = REPO + "/arch/x86/entry/syscalls/syscall_32.tbl"
SYSCALL_64 = REPO + "/arch/x86/entry/syscalls/syscall_64.tbl"
header_32 = "sysnums_32.h"
header_64 = "sysnums_64.h"


def get_tbl_list(src):
    tbl = list()
    with urllib.request.urlopen(src) as f:
        for line in f:
            line = line.decode('ascii')
            if line.startswith("#"):
                continue
            elems = line.split()

            if len(elems) >= 3:
                sysnum = elems[0]
                name = elems[2]
                sysname = "SYS_" + name
                tbl.append((sysnum, name, sysname))
    return tbl


def emit_header(name, tbl):
    guard = name.replace(".", "_").upper()

    with open(name, 'w') as f:
        f.write("#ifndef " + guard + "\n")
        f.write("#define " + guard + "\n\n")
        f.write("// AUTO-GENERATED, DO NOT MODIFY\n\n\n")

        for line in tbl:
            f.write("#define\t\t")
            f.write(line[2]+"\t\t")
            f.write(line[0]+"\t\t")
            f.write("//"+line[1]+"\n")

        f.write("\n#endif\n")


def main():
    tbl32 = get_tbl_list(SYSCALL_32)
    tbl64 = get_tbl_list(SYSCALL_64)
    emit_header(header_32, tbl32)
    emit_header(header_64, tbl64)


if __name__ == '__main__':
    main()
