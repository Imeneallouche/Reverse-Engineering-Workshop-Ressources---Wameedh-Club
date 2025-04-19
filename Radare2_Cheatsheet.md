## 🧠 Radare2 Reverse Engineering Cheatsheet

### 🔰 Start & Analyze

```bash
r2 <binary>        # Open binary in radare2
r2 -d <binary>     # Debug mode
aaa                # Analyze all (functions, symbols, etc.)
aac                # Analyze all calls
afl                # List all functions
```

---

### 📍 Navigation

```bash
s <addr>           # Seek to address (ex: s 0x00400510)
s sym.main         # Seek to main
s+ 0x10            # Seek forward
s- 0x10            # Seek backward
pd <n>             # Disassemble next n instructions (ex: pd 20)
pdf                # Disassemble function
V                  # Visual mode
VV                 # Visual Graph mode (press `?` for help)
```

---

### 🧩 Functions, Symbols, Xrefs

```bash
afl                # List functions
afn <new_name>     # Rename function
axg <addr>         # Graph cross references
axt <addr>         # Show xrefs to
axtj <addr>        # Xrefs to in JSON
```

---

### 🔍 Searching

```bash
/ <string>         # Search for string
/ <hex>            # Search for hex pattern (ex: / 90 90)
iz                 # List strings in binary
iz~"flag"          # Search for flag in strings
/ja <value>        # Search for immediate value
/afs <string>      # Search for string in functions
```

---

### 🛠️ Patching

```bash
wa <opcode>        # Write assembly at current address (e.g., wa nop)
wx <hex>           # Write hex bytes (e.g., wx 90909090)
ood                # Restart debugged process
```

---

### 🐞 Debugging

```bash
ood                # Restart debug session
db <addr>          # Set breakpoint
db sym.main        # Break at main
dc                 # Continue
ds                 # Step into
dso                # Step over
dr                 # Show registers
dr eax=0x1234      # Set register
px @ esp           # Show stack contents
```

---

### 📦 Memory & Stack

```bash
px <n>             # Hexdump n bytes at current address
px @ esp           # Dump stack
x <fmt> @ <addr>   # Examine memory (e.g., x 4wx @ esp)
```

---

### 🧠 Misc Tools

```bash
iI                 # Show binary info
ie                 # List entrypoints
iS                 # Sections
iM                 # Memory maps
izz                # All strings
it                 # List symbols from import table
ii                 # Imports
is                 # Symbols
```

---

### 🧠 Scripting & Automation

```bash
#!pipe             # Send output to shell command
> file             # Redirect output
. <script.r2>      # Run radare2 script
```

---

### 💻 Binary Exploitation Tips

- Check protections:

  ```bash
  i~canary         # Check for stack canary
  i~nx             # Check NX bit
  i~pic            # Check PIE
  i~relro          # Check RELRO
  ```

- Format string vulnerability:

  ```bash
  iz~%             # Look for format strings
  ```

- Shellcode testing:
  ```bash
  wx <shellcode>   # Inject shellcode
  ```

---

### ✨ Visual Mode Hotkeys

```text
p         # Change view (hex, disasm, etc.)
s         # Seek
x/X       # Zoom in/out (Graph mode)
TAB       # Switch views
```
