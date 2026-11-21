# Goals for learning Arduino

this doc will walk you through setting up everything we need for working on projects together: a C compiler (`clang`), `make`, `git`, `ssh`, and `VS Code`. if you get stuck anywhere, send a screenshot or photo of what you see in the group, and we will sort it out together.

wherever you see a checkbox like `- [ ]`, that is a step to do. when the doc says "send a photo of the output", I just want to see that the command worked on your machine.

- [ ] If on Windows
  - only for the following installation steps, run every command in administrative `PowerShell`, unless instructed to run in `GitBash`
  - to open administrative `PowerShell`: press the `Start` button, type `PowerShell`, right-click on it, and click `Run as administrator`.
  - run `winget --version`. if `winget` says it is "not recognized", open the Microsoft Store, search for `App Installer`, and install or update it. then try again. otherwise, continue reading.
  - after ALL of the installation on Windows is completed, always use `GitBash` as the primary terminal, unless instructed to use `PowerShell`.
  - [ ] install `GitBash`
    - [ ] run `winget install --id Git.Git -e`
    - [ ] open `GitBash` from the start menu.
    - [ ] run `pwd`, and send a photo of the output in the group.
  - [ ] install `clang`
    - [ ] run `winget install --id LLVM.LLVM -e`
    - [ ] the installer does not add `clang` to your `PATH` (this is what lets the terminal find `clang`), so we have to do it ourselves:
      - [ ] press the `Start` button, type `environment variables`, and open `Edit the system environment variables`.
      - [ ] click on `Environment Variables...`.
      - [ ] in the **top** box (`User variables for <your username>`), click on `Path`, and then on `Edit...`.
      - [ ] click on `New`, paste `C:\Program Files\LLVM\bin`, and press `Enter`.
      - [ ] click `OK` at the bottom right on all the windows to close them.
    - [ ] open a **new** `GitBash` from the start menu (an already open one won't see the changes).
    - [ ] run `clang --version`, and send a photo of the output in the group.
  - [ ] install `make`
    - [ ] run `Get-ExecutionPolicy`. If it returns `Restricted`, then run `Set-ExecutionPolicy AllSigned`.
    - [ ] run `Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))`.
    - [ ] close `PowerShell`, and open administrative `PowerShell` again. then run `choco install make`
    - [ ] open a **new** `GitBash` from the start menu.
    - [ ] run `make --version`, and send a photo of the output in the group.
- [ ] If on macOS, open `Terminal`
  - to open `Terminal`: press `Cmd + Space`, type `Terminal`, and press `Enter`.
  - [ ] install `make` and `clang`
    - [ ] if you have not already installed both of them, run `xcode-select --install`
    - [ ] click on `Install` in the pop-up, and agree to the ToS. this takes a few minutes.
    - [ ] run `clang --version` and `make --version`, and send a photo in the group.
    - this also installs `git`, so you don't need to install it separately.
- [ ] If on Linux, open your favorite terminal
  - [ ] ensure `clang`, `make`, `git` and the `ssh` client are installed. run the line for your distro:
    - Debian/Ubuntu based distros: `sudo apt install clang make git openssh-client`
    - Fedora: `sudo dnf install clang make git openssh-clients`
    - Arch: `sudo pacman -S clang make git openssh`
  - [ ] run `clang --version` and `make --version`, and send a photo in the group.
- [ ] set up GitHub account.
  - [ ] sign up at [https://github.com/signup](https://github.com/signup), and verify your email address when GitHub sends you the mail.
  - if you don't want your real email address to show up in the commits you make(commits will be explained later), go to [https://github.com/settings/emails](https://github.com/settings/emails), and tick `Keep my email addresses private`. GitHub will then give you a `...@users.noreply.github.com` address, which you can use in the next steps instead of your real email.
- [ ] setting up `git`
  - just a reminder, on Windows, use `GitBash` as the primary terminal unless instructed otherwise. for Linux/macOS, you are free to use any terminal.
  - [ ] run `git config --global user.name "<name>"`
  - [ ] run `git config --global user.email "<email>"`, use the same email you used for GitHub (or the `noreply` one from above).
  - [ ] run `git config --global init.defaultBranch main`
  - [ ] run `git config --global --list`, and send a photo of the output in the group.
- [ ] setting up `ssh`.
  - [ ] setting up public/private key.
    - [ ] run `ssh-keygen -t ed25519 -C "<your github email>"`
    - [ ] you will be prompted with `Enter a file in which to save the key (/home/$USER/.ssh/id_ed25519): `, where `$USER` will be replaced with your desktop username. the exact path looks a bit different on macOS and Windows, that is fine. here, simply press `Enter`.
    - [ ] if it says that the file already exists and asks `Overwrite (y/n)?`, type `n`, and ask in the group. you might already have a key that you don't want to lose.
    - [ ] think of a secure passphrase, then enter it in the following prompts. remember it, because nobody (including us) can recover it for you. please note that while typing passphrases/passwords, the terminal usually doesn't render any character, or replaces all characters with '*', for security reasons. however, it does not mean your passphrase/password has been altered, they remain exactly the same as you typed and entered them in the terminal.
      ```bash
      > Enter passphrase (empty for no passphrase): [Type a passphrase]
      > Enter same passphrase again: [Type passphrase again]
      ```
    - [ ] run `cat $HOME/.ssh/id_ed25519.pub`
    - [ ] select the entire output (it is a single long line, starting with `ssh-ed25519` and ending with your email), and copy it by pressing `Ctrl + Shift + C` (`Cmd + C` on macOS). on `GitBash`, `Ctrl + Insert` works as well.
    - [ ] open a browser of your choice in which you are logged into your GitHub account, and open [https://github.com/settings/keys](https://github.com/settings/keys)
    - [ ] click on `New SSH key`.
    - [ ] give your ssh key some unique name so that you can remember that this key belongs to your laptop's `ssh`.
    - [ ] paste the previously copied line in the `Key` textbox, leave `Key type` on `Authentication key`, and click on `Add SSH key`.
    - [ ] authenticate yourself if GitHub is asking you to.
  - [ ] verify ssh connection to GitHub.
    - [ ] run `ssh -T git@github.com`
    - [ ] the first time, it will ask `Are you sure you want to continue connecting (yes/no/[fingerprint])?`. type `yes` (the whole word) and press `Enter`.
    - [ ] enter your ssh passphrase when prompted.
    - [ ] check that the output says something along the lines of
    ```bash
    Hi <github username>! You've successfully authenticated, but GitHub does not provide shell access.
    ```
    - [ ] if you get the above output, ssh and github connection is completed.

- [ ] setting up `Projects` folder.
  - [ ] open the terminal (`GitBash` on Windows).
  - [ ] run `mkdir -p $HOME/Projects`
  - this will create a `Projects` directory in your home directory (on Windows, this is `C:\Users\<your username>`). this is the convention for where your project folders should be located. for each project, just create a folder inside `Projects`. for example, running `mkdir -p $HOME/Projects/Python` will create a `Python` sub-directory inside your `Projects` directory. we will see how to create files in this folder just down below.

- [ ] Install and setup `VS Code`.
  - [ ] install VS Code for your OS.
    - **Windows**: in administrative `PowerShell`, run `winget install --id Microsoft.VisualStudioCode -e`
    - **macOS**: download it from [https://code.visualstudio.com](https://code.visualstudio.com), open the downloaded zip, and drag `Visual Studio Code` into your `Applications` folder.
    - **Linux**: download the package for your distro from [https://code.visualstudio.com](https://code.visualstudio.com) (`.deb` for Debian/Ubuntu, `.rpm` for Fedora), or install it through your distro's package manager if you prefer. if you are not sure which one to pick, ask in the group.
  - [ ] **macOS only**: let VS Code add the `code` command to your terminal.
    - [ ] open VS Code from `Applications`.
    - [ ] press `Cmd + Shift + P` to open the Command Palette.
    - [ ] type `shell command`, and pick `Shell Command: Install 'code' command in PATH`.
    - [ ] close VS Code.
  - [ ] close and reopen your terminal (`GitBash` on Windows), so that it can find the new `code` command.
  - [ ] create the folder we will be working in.
    - [ ] run `mkdir -p $HOME/Projects/Learning-C`
    - [ ] run `cd $HOME/Projects/Learning-C`
    - [ ] run `pwd`, and check that the output ends with `Projects/Learning-C`.
  - [ ] open that folder in VS Code.
    - [ ] while still inside `Learning-C` in your terminal, run `code .` (yes, there is a dot at the end, it means "the folder I am currently in").
    - [ ] VS Code will open, and will ask `Do you trust the authors of the files in this folder?`. this is your own folder, so click `Yes, I trust the authors`.
    - [ ] if you see a `Welcome` tab, you can just close it.
    - [ ] on the left side, you should see the `Explorer` pane with `LEARNING-C` as the folder name at the top. it will be empty for now. if you can't see the pane, press `Ctrl + Shift + E` (`Cmd + Shift + E` on macOS).
  - [ ] create `hello.c` from the `Explorer` pane.
    - [ ] hover your mouse over the `LEARNING-C` title in the `Explorer` pane. a few small icons will show up on the right.
    - [ ] click on the first one, `New File`.
    - [ ] type `hello.c`, and press `Enter`.
    - [ ] the file will open in the editor on the right. if VS Code suggests installing extensions for C/C++, you can ignore (or close) the pop-up for now.
  - [ ] write your first program. type (or copy-paste) the following in `hello.c`
    ```c
    #include <stdio.h>

    int main(void) {
        printf("Hello, world!\n");
        return 0;
    }
    ```
  - [ ] save the file by pressing `Ctrl + S` (`Cmd + S` on macOS). if you forget to save, the compiler will compile an empty file, and will complain. the white dot next to the `hello.c` tab in the tab ribbon above means you have unsaved changes. if there is a cross symbol there, then your changes in the file has been saved.
  - [ ] open the VS Code embedded terminal.
    - [ ] press `` Ctrl + ` `` (that is the backtick key, usually just above `Tab`), or click on `Terminal > New Terminal` or `View > Termnial` in the top menu bar.
    - [ ] a terminal panel will appear at the bottom of VS Code.
  - [ ] **Windows only**: make `GitBash` the default terminal in VS Code.
    - [ ] press `Ctrl + Shift + P` to open the Command Palette.
    - [ ] type `Terminal: Select Default Profile`, and press `Enter`.
    - [ ] pick `Git Bash` from the list.
    - [ ] in the right-side of the terminal panel, click on the little trash can icon to close the current terminal (probably `PowerShell`).
    - [ ] open the a new terminal by selecting `View > Terminal` from the menu bar. this terminal should be `Git Bash`. you can double check by looking at the top right of the terminal panel, it should say `bash` or `Git Bash`.
  - **Linux/macOS**: you don't need to change anything, the default terminal is already what you want.
  - [ ] check that the terminal is in the right folder.
    - [ ] run `pwd`, the output should end with `Projects/Learning-C`.
    - [ ] run `ls`, the output should show `hello.c`.
  - [ ] compile your program.
    - [ ] run `clang hello.c -o hello`
    - [ ] if everything went well, it will print nothing, and just give you the prompt back. no news is good news here.
    - [ ] run `ls` again. you should see a new file `hello` (`hello.exe` on Windows), that is your compiled program!
  - [ ] run your program.
    - [ ] run `./hello`
    - [ ] you should see `Hello, world!` printed in the terminal.
    - [ ] send a screenshot of your VS Code window (with `hello.c` and the terminal output visible) in the group. congratulations, you just wrote, compiled and ran your first C program!
  - if something went wrong
    - `clang: command not found`: close and reopen VS Code completely, so that it picks up the updated PATH. if it still fails (on Windows, double check the `Path` step in the `clang` installation above), ask in the group.
    - `error: no such file or directory: 'hello.c'`: you are in the wrong folder. run `pwd` and `ls`, and `cd` into `Learning-C`.
    - **Windows only**: `fatal error: 'stdio.h' file not found`, or `unable to find a Visual Studio installation`: the `Build Tools` from the `clang` installation are missing or incomplete. open `Visual Studio Installer`, click `Modify` on the `Build Tools`, and make sure `Desktop development with C++` is checked. if it still fails, ask in the group.
