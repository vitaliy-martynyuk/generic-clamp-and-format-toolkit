# Generic Clamp & Format Toolkit

A small C++ template toolkit — `clamp`, `inRange`, `describe`, `typeName`
— built to explore how function overloading, templates, and default
arguments interact (and sometimes collide), plus an interactive session
menu that exercises all four and reuses validation, state-hiding, and
retry logic from earlier projects.

Built as a learning project while working through
[learncpp.com](https://www.learncpp.com/), focused on consolidating
Chapter 11: function templates, overload resolution, template argument
deduction, and the specific ways defaults and overloads can become
ambiguous. The session menu deliberately folds in earlier material —
Ch 7 state-hiding, Ch 8 loops, Ch 9 stream-failure recovery and
preconditions, and bit flags — so older material stays in active use
rather than just the current chapter.

## What it does

- `clamp(v, min, max)` — a single function template (collapsed from
  three near-identical type-specific overloads) that forces a value
  into a range
- `inRange(v, min, max, inclusive = true)` — a template with a
  well-behaved default argument, used as a deliberate contrast to a
  broken default-argument overload explored (and discarded) during
  development
- `describe(label, value)` — overloaded per type (`int`, `double`,
  `float`, `bool`) with genuinely different formatting per type, and a
  deleted catch-all template that rejects any other type at compile time
- `typeName(value)` — a generic template with explicit specializations
  for `int`, `double`, `float`, and `bool`, falling back to
  `"unsupported"` for anything else
- An interactive menu (`main.cpp` + `session`) that lets you pick one of
  the four functions to run against fixed demo values, tracks which
  functions were exercised via bit flags, and prints a session summary
  when you quit or hit the session cap

## Project structure

```
main.cpp                    // program entry point, orchestrates the menu loop
helpers/
  helpers.h                 // umbrella include for the toolkit
  clamp.h                   // clamp function template
  in_range.h                // inRange function template with a default argument
  describe.h                // describe overloads + deleted catch-all template
  type_name.h               // typeName template + explicit specializations
io/
  io.h / io.cpp             // reading the menu choice, printing errors,
                            //   and stream-failure recovery
validate/
  validate.h / .cpp         // isFunctionCodeValid() / isUserInputValid()
session/
  session.h / .cpp          // hidden session counter + bit flags,
                            //   read+validate+retry loop, session summary
consts/
  consts.h                  // menu codes and the session cap
```

## Building

Requires a C++20-capable compiler.

```bash
g++ -std=c++20 -Wall -Wextra -Wconversion -Wshadow -Wsign-conversion -o app \
    main.cpp io/io.cpp validate/validate.cpp session/session.cpp
```

Or open `Generic Clamp & Format Toolkit.slnx` in Visual Studio.

## Running

```bash
./app
```

Example session:

```
Enter function code ('c' - clamp, 'r' - inRange, 'd' - describe, 't' - typeName) or 'q' to quit: c
clamp(10, 1, 5) = 5
Enter function code ('c' - clamp, 'r' - inRange, 'd' - describe, 't' - typeName) or 'q' to quit: q
Quitting...

-----------------------------------
Total functions used: 1
clamp used?: yes
describe used?: no
inRange used?: no
typeName used?: no
```

## Notes

`clamp`'s single-template design was reached by first writing three
type-specific overloads, noticing the duplication, then collapsing them
— along the way, a call like `clamp(5, 1, 10.0)` was deliberately left
unresolved by deduction to see the real compiler error, and resolved via
an explicit template argument (`clamp<double>(...)`) rather than adding
`std::common_type_t`-based implicit promotion, matching the real
`std::clamp`'s own design choice. A second template overload with a
fixed-type default parameter was deliberately built to trigger — and
correctly diagnosed — a genuine overload ambiguity for `double`
arguments, then discarded in favor of the single clean template.
`describe`'s formatting builds each line in a local `std::ostringstream`
rather than mutating `std::cout`'s persistent state directly, after an
earlier version was found to leak formatting flags into unrelated,
later `cout` output. Session state (the counter and usage bit flags) is
hidden behind functions in `session.cpp`, and the session ends the same
way — printing the same summary — whether the user quits manually or
the session cap is reached first.