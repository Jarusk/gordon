#! /bin/env python3

import urllib.request

REPO = "https://raw.githubusercontent.com/torvalds/linux/master"
SYSCALL_32 = REPO + "/arch/x86/entry/syscalls/syscall_32.tbl"
SYSCALL_64 = REPO + "/arch/x86/entry/syscalls/syscall_64.tbl"
out_path = "../arch/common/"
header_32 = "sysnums_32.h"
header_64 = "sysnums_64.h"
guard_64 = "SYS_SYSCALL_64_H"
guard_32 = "SYS_SYSCALL_32_H"


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
                if int(sysnum) < 512:
                    tbl.append((sysnum, name, sysname))
    return tbl


def emit_header(out_dir, name, guard, tbl):

    with open(out_dir+"/"+name, 'w') as f:
        f.write("#ifndef " + guard + "\n")
        f.write("#define " + guard + "\n\n")
        f.write("// AUTO-GENERATED, DO NOT MODIFY\n// "+name+"\n\n\n")

        for line in tbl:
            f.write("#define\t")
            f.write(line[2]+"\t\t")
            f.write(line[0]+"\t")
            f.write("//"+line[1]+"\n")

        f.write("\n#endif\n")


def main():
    tbl32 = get_tbl_list(SYSCALL_32)
    tbl64 = get_tbl_list(SYSCALL_64)
    emit_header(out_path, header_32, guard_32, tbl32)
    emit_header(out_path, header_64, guard_64, tbl64)


if __name__ == '__main__':
    main()
