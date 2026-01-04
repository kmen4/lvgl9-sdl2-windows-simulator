# Contributing Guidelines

Thank you for your interest in contributing to this project.  
This repository is maintained in my spare time, so please understand that response times for
issues and pull requests may vary.

The goal of this project is to provide a clean, minimal, and reproducible LVGL 9.4.0 + SDL2
simulator for Windows. Contributions are welcome as long as they align with that goal.

---

## 🐞 Reporting Issues

Before opening an issue, please:

1. Make sure you are using the latest version of the repository.
2. Check whether the issue already exists.

When reporting a bug, **a complete and minimal testcase is required**.  
Issues without a reproducible testcase may be closed without investigation.

A good testcase includes:

- A clear description of the problem  
- The expected behavior  
- The actual behavior  
- A minimal code snippet or steps to reproduce  
- Your environment details:
  - LVGL version  
  - Compiler version (MSVC)  
  - Windows version  
  - VS Code or Visual Studio version  

---

## 🔧 Pull Requests

Pull requests are welcome, but please follow these guidelines:

- Keep PRs focused and easy to review.
- Avoid large refactors, formatting-only changes, or unrelated modifications.
- Explain the purpose of the change clearly.
- Ensure the project still builds cleanly on Windows with MSVC.
- Do not introduce new external dependencies or submodules.

If your PR fixes a bug, include the testcase in the PR description.

---

## 🎯 Project Scope

This project intentionally aims to be:

- Minimal  
- Reproducible  
- Windows-focused  
- Free of submodules  
- Free of external dependencies  

Contributions that add complexity, multi-platform layers, or unnecessary abstractions are unlikely
to be accepted.

---

## 🙏 Thank You

Even if I cannot respond immediately, contributions, ideas, and improvements are appreciated.
This project exists to help the LVGL community, and your effort helps make it better.
