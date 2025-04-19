## 🐞 GDB Reverse Engineering & Exploitation Cheatsheet

### 🚀 Starting GDB

```bash
gdb <binary>               # Start GDB with binary
gdb -q <binary>            # Start without banner
gdb -ex "start" <binary>   # Start and break at main
```

---

### 🧭 Execution Controls

```bash
start                 # Run program and stop at main
run (r)               # Run/restart program
continue (c)          # Resume execution
next (n)              # Next line (step over)
step (s)              # Step into function
finish                # Run until function returns
until <addr/line>     # Run until reaching address/line
```

---

### 📍 Breakpoints & Watchpoints

```bash
b main                # Break at function
b *0x080484a2         # Break at address
b 24                  # Break at line 24
info b                # List breakpoints
d <n>                 # Delete breakpoint number n
watch <var>           # Watch variable (read/write)
rwatch <var>          # Watch for read
awatch <var>          # Watch for read/write
```

---

### 🕵️ Inspection

```bash
x/<n><f> <addr>       # Examine memory (e.g., x/4x $esp)
formats: x = hex, d = dec, s = string, i = asm instr
p <expr>              # Print value (e.g., p $eax)
p/x $eax              # Print eax in hex
info registers        # Show all registers
info locals           # Show local variables
info args             # Show function args
```

---

### 🧱 Stack & Memory

```bash
x/16x $esp            # Examine 16 words at stack
x/s $esp              # String at top of stack
x/40wx 0xdeadbeef     # 40 words at address
set $esp=0xdeadbeef   # Set ESP
bt                    # Backtrace (call stack)
frame <n>             # Switch to stack frame n
```

---

### 🛠️ Modify Execution

```bash
set var <var>=<val>   # Set variable value
set $eax=0x1337       # Set register
call <func>(args)     # Call a function manually
jump *0x080484a2      # Jump to address
```

---

### 🔍 Searching Memory

```bash
find <start>, <end>, <pattern>
find 0x08048000, +1000, "flag"
```

---

### ⛏️ Assembly & Disassembly

```bash
disas <func>          # Disassemble function
disas /m main         # Mixed C + ASM
x/10i $pc             # 10 instructions from PC
layout asm            # TUI asm view
layout src            # TUI source view
```

---

### 🐚 Shellcode Testing (Optional)

```bash
run < <input>         # Provide input
set {char[100]} $esp = "..."  # Inject shellcode
```

---

### 🧪 TUI Mode (Graphical Interface)

```bash
gdb -tui <binary>     # Start with TUI
Ctrl+X A              # Toggle TUI mode
layout regs           # View registers
layout split          # Split view src+asm
```

---

### 📦 GDB Extensions for RE

- **pwndbg** – Modern GDB enhancement for pwners
- **gef** – Lightweight GDB Exploitation Framework
- **PEDA** – Python Exploit Development Assistance

```bash
# Install pwndbg (example)
git clone https://github.com/pwndbg/pwndbg
cd pwndbg && ./setup.sh
```

---

### 🛡️ Check Binary Protections

```bash
checksec             # If using pwndbg
# Or manually:
readelf -h <bin>     # Check for PIE/NX
readelf -s <bin>     # Check for symbols
```
