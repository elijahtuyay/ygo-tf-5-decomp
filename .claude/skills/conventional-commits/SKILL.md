---
name: conventional-commits
description: >
  Enforces Conventional Commits formatting for this repository. Activate whenever
  creating a git commit in this project. Triggers: "commit", "git commit",
  "commit message", "conventional commit".
---

# Conventional Commits for this repository

All commits in this repository follow the [Conventional Commits](https://www.conventionalcommits.org/)
specification.

## Format

```
<type>(<optional scope>): <description>
```

- **Headline only, no body**, unless the user explicitly asks for one.
- `<description>`: imperative mood, lowercase, no trailing period.
- Keep the whole line under ~70 characters.

## Types

| Type | When to use |
|---|---|
| `feat` | a new function is matched, a new module/config is added, new tooling capability |
| `fix` | correcting a wrong address/type/logic in previously-drafted C |
| `docs` | documentation-only changes (`docs/`, `README.md`, skill files) |
| `build` | build system / splat config / linker script changes |
| `chore` | tooling, scripts, `.gitignore`, dependency/setup changes |
| `refactor` | restructuring existing (already-matched or draft) code without changing behavior |
| `test` | changes to verification scripts/tooling only |

## Scope

Use the module or area touched as the scope when it disambiguates, e.g.:
`feat(rel_movie_viewer): match func_00000138`, `chore(tools): fetch wibo and mwccpsp`,
`docs(matching): document local relocation-aware diff`.

## Examples

```
feat(rel_movie_viewer): match 8 more functions locally
chore(tools): auto-fetch wibo and mwccpsp in setup_tools.sh
docs: document local matching workflow and known-address table
build(rel_movie_viewer): add full section-accurate splat config
```
