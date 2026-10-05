# Public Source Inventory

This inventory distinguishes files that are present from features that require missing project components.

## Present

- C++ callbacks for user information, robot dispatch and AI decision results.
- Timer and batch robot data fragments.
- Text-form protocol resources for login, hall, clubs, game records, configuration, chat and poker messages.
- Unity scene metadata for Login, Hall, GamePlay3D, Splash and Upgrade.
- API and deployment reference documents.
- Eight product screenshots.

## Not present in the public repository

- A complete CMake, Make, Maven, Gradle or Unity project build definition.
- All headers and implementations referenced by the C++ fragments.
- Database schemas and migrations.
- Executable service entry points and complete runtime configuration.
- Unity `.unity` scene files, scripts, packages and project settings.
- A test suite proving protocol compatibility or game-rule correctness.

## Evaluation rule

Screenshots and protocol definitions document product intent and interfaces. They do not establish that every depicted feature is implemented or deployable from this repository alone.
