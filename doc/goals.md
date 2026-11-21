# Goals for learning Arduino

- [ ] If on Windows
  - only for the following installation steps, run every command in administrive `Powershell`, unless instructud to run in `GitBash`
  - after ALL of the installation on Windows is completed, always use `GitBash` as the primary terminal, unless instructed to use `PowerShell`.
  - [ ] install `GitBash`
    - [ ] run `winget install --id Git.Git -e`
    - [ ] open `GitBash` from the start menu.
    - [ ] run `pwd`, and send a photo of the output in the group.
  - [ ] install `clang`
    - [ ] run `winget install --id LLVM.LLVM`
    - [ ] open `GitBash` from the start menu.
    - [ ] run `clang --version`, and send a photo of the output in the group.
  - [ ] install `make`
    - [ ] run `Get-ExecutionPolicy`. If it returns `Restricted`, then run `Set-ExecutionPolicy AllSigned`.
    - [ ] run `Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))`.
    - [ ] restart `PowerShell`, then run `choco install make`
    - [ ] open `GitBash` from the start menu.
    - [ ] run `make --version`, and send a photo of the output in the group.
- [ ] If on macOS, open `Terminal`
  - [ ] install `make` and `clang`
    - [ ] if you have not already installed both of them, run `xcode-select --install`
    - [ ] click on `Install` in the pop-up, and agree to the ToS.
    - [ ] run `clang --version` and `make --version`, and send a photo in the group.
- [ ] if on Linux, just ensure `clang` is installed and in your PATH.
- [ ] set up GitHub account.
- [ ] setting up `git`
  - just a reminder, on Windows, use `GitBash` as the primary terminal unless instructed otherwise. for Linux/macOS, you are free to use any terminal.
  - [ ] run `git config --global user.name "<name>"`
  - [ ] run `git config --global user.email "<email>"`
  - [ ] run `git config --global --list`, and send a photo of the output in the group.
- [ ] setting up `ssh`.
  - [ ] setting up public/private key.
    - [ ] run `ssh-keygen -t ed25519 -C <your github email>`
    - [ ] you will be prompted with `Enter a file in which to save the key (/home/$USER/.ssh/id_ed25519): `, where `$USER` will be with replaced your desktop username. here, simply press `Enter`.
    - [ ] think of a secure passphrase, then enter it in the following prompts. please note that while typing passphrases/passwords, the terminal usually doesn't render any character, or replaces all characters with '*', for security reasons. however, it does not meant your passphrase/password has been altered, they remain exactly the same as you typed and entered them in the terminal.
      ```bash
      > Enter passphrase (empty for no passphrase): [Type a passphrase]
      > Enter same passphrase again: [Type passphrase again]
      ```
    - [ ] run `cat $HOME/.ssh/id_ed25519.pub`
    - [ ] select the entire output, and copy it by pressing `Ctrl + Shift + C`
    - [ ] open a browser of your choice in which you are logged into your GitHub account, and open [https://github.com/settings/keys](https://github.com/settings/keys)
    - [ ] click on `New SSH key`.
    - [ ] give your ssh key some unique name so that you can remember that this key belongs to your laptop's `ssh`.
    - [ ] paste the previously copied line in the `Key` textbox, leave `Key type` on `Authentication key`, and click on `Add SSH key`.
    - [ ] authenticate yourself if GitHub is asking you to.
  - [ ] verify ssh connection to GitHub.
    - [ ] run `ssh -T git@github.com`, and enter your ssh passphrase when prompted.
    - [ ] check that the output says something along the lines of
    ```bash
    Hi <github username>! You've successfully authenticated, but GitHub does not provide shell access.
    ```
    - [ ] if you get the above output, ssh and github connection is completed.

- [ ] setting up `Projects` folder.
  - [ ] open the terminal.
  - [ ] run `mkdir $HOME/Projects`
  - this will create a `Projects` directory in your home directory. this is the convention for where your project folders should be located. for each project, just create a folder inside `Projects`. for example, run `mkdir -p $HOME/Projects/Learning-C`, will create a `Learning-C` sub-directory inside your `Projects` directory. we will see how to create files in this folder just down below.

- [ ] Install and setup `VS Code`.
  - [ ] install VS Code for your OS.
  - [ ] open VS Code.
  - [ ] --- TODO ---
