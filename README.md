<!-- SONAM NARULA · 23BCON0190 · JECRC UNIVERSITY · CRT 2026 -->

<div align="center">

# The Placement Arc
### one deploy target. everything else is just a metric.

**Sonam Narula** · B.Tech CSE '27 · JECRC University

<br/>

![pipeline](https://img.shields.io/badge/pipeline-passing-2ea44f?style=flat-square&logo=githubactions&logoColor=white&labelColor=1a1a1a)
&nbsp;![runner](https://img.shields.io/badge/runner__pool-alpha--m-1a1a1a?style=flat-square)
&nbsp;![builds](https://img.shields.io/badge/builds-15%2F15_green-2ea44f?style=flat-square&labelColor=1a1a1a)
&nbsp;![coverage](https://img.shields.io/badge/coverage-94.4%25-2ea44f?style=flat-square&labelColor=1a1a1a)
&nbsp;![day](https://img.shields.io/badge/day-047-1a1a1a?style=flat-square)

</div>

<br/>

---

<br/>

## `pipeline.config`

```yaml
pipeline:
  owner: Sonam Narula
  repo: the-placement-arc
  branch: placement/CRT-2026
  runner_pool: alpha-m          # promoted from: standard-6m — not the target, just telemetry
  current_stage: dsa-tests
  day: 47
  target: offer_letter.json     # the only field that actually matters
  status: building
```

<br/>

---

<br/>

## event log — runner pool upgrade (side-effect, not the target)

```
$ ci-bot --event runner-promotion

[2026-05-16 09:00]  EVENT  runner_pool.upgrade
  from   : standard-6m
  to     : alpha-m
  reason : 15 consecutive green builds
           mean coverage 94.4%
           3 builds at 100% coverage

note: runner pools aren't requested. they're computed
      from build history on every push. this one just
      ran the numbers and moved itself.

      but the deploy target hasn't changed. it never was
      "alpha-m." it's still offer_letter.json.
```

<br/>

---

<br/>

## pipeline stages

```
 ┌────────────┐    ┌────────────┐    ┌────────────┐    ┌────────────┐    ┌────────────┐
 │  STAGE 1   │ →  │  STAGE 2   │ →  │  STAGE 3   │ →  │  STAGE 4   │ →  │  STAGE 5   │
 │  C++ & OOP │    │    DSA     │    │  Core CS   │    │  Aptitude  │    │ Interview  │
 │  ✓ PASSED  │    │  ▶ RUNNING │    │  ⋯ QUEUED  │    │  ⋯ QUEUED  │    │  ⋯ QUEUED  │
 └────────────┘    └────────────┘    └────────────┘    └────────────┘    └────────────┘
                                                                                 │
                                                                                 ▼
                                                                       ┌──────────────────┐
                                                                       │   DEPLOY: PROD    │
                                                                       │  offer_letter.json│
                                                                       │   ⋯ PENDING       │
                                                                       └──────────────────┘

 async job  →  german_language.service ··· RUNNING (background)
```

<br/>

---

<br/>

## `notes.yml` — why this pipeline doesn't break

```yaml
# a build pipeline has no concept of "bad days," only builds
# that ran and builds that didn't. this one has run every
# single day. zero skipped jobs, zero --force-skip.

# runner_pool was never a hardcoded value in the config — it's
# derived from build_history on every push. standard-6m to
# alpha-m wasn't granted by anyone. it was computed.

# there's no retry_limit set on effort here. only on patience,
# and that's still being tuned.

# one test score is a sample size of one. fifteen green builds
# in a row, averaging 94.4%, is a distribution you can trust.

# the only failure mode this pipeline actually has is the
# quiet kind — the one where it just stops running. that
# hasn't happened in 47 days, and it isn't scheduled to.
```

<br/>

---

<br/>

## build history

| Build | Date | Job | Score | Coverage | Status |
|:-:|:--|:--|:-:|:-:|:-:|
| `#001` | 02 May 2026 | [C Programming Basics](./daily-tests/CBT-01.md) | 40 / 45 | 95.2% | **PASS** |
| `#002` | 02 May 2026 | [C Programming Basics](./daily-tests/CBT-02.md) | 44 / 45 | 97.8% | **PASS** |
| `#003` | 04 May 2026 | [Daily Test](./daily-tests/CBT-03.md) | 44 / 45 | 97.8% | **PASS** |
| `#004` | 05 May 2026 | [Daily Test](./daily-tests/CBT-04.md) | 43 / 45 | 95.6% | **PASS** |
| `#005` | 06 May 2026 | [FOP Daily Test](./daily-tests/CBT-05.md) | 39 / 45 | 86.7% | **PASS** |
| `#006` | 07 May 2026 | [OOP Daily Test](./daily-tests/CBT-06.md) | 45 / 45 | 100.0% | **PASS ★** |
| `#007` | 08 May 2026 | [OOP Daily Test](./daily-tests/CBT-07.md) | 45 / 45 | 100.0% | **PASS ★** |
| `#008` | 09 May 2026 | [OOP Daily Test](./daily-tests/CBT-08.md) | 43 / 45 | 95.6% | **PASS** |
| `#009` | 10 May 2026 | [DSA Daily Test](./daily-tests/CBT-09.md) | 41 / 45 | 91.1% | **PASS** |
| `#010` | 11 May 2026 | [DSA Daily Test](./daily-tests/CBT-10.md) | 38 / 45 | 84.4% | **PASS** |
| `#011` | 12 May 2026 | [DSA Daily Test](./daily-tests/CBT-11.md) | 40 / 45 | 88.9% | **PASS** |
| `#012` | 13 May 2026 | [DSA Daily Test](./daily-tests/CBT-12.md) | 44 / 45 | 97.8% | **PASS** |
| `#013` | 14 May 2026 | [DSA Daily Test](./CBT%2013.png) | 45 / 45 | 100.0% | **PASS ★** |
| `#014` | 15 May 2026 | [Linked List](./CBT%2014.png) | 43 / 45 | 95.6% | **PASS** |
| `#015` | 16 May 2026 | [DSA Daily Test](./CBT%2015.png) | 43 / 45 | 95.6% | **PASS** |

<br/>

---

<br/>

## build environment

![C++](https://img.shields.io/badge/C%2B%2B-1a1a1a?style=flat-square&logo=cplusplus&logoColor=white)
&nbsp;![Git](https://img.shields.io/badge/Git-1a1a1a?style=flat-square&logo=git&logoColor=white)
&nbsp;![GitHub](https://img.shields.io/badge/GitHub-1a1a1a?style=flat-square&logo=github&logoColor=white)
&nbsp;![VS Code](https://img.shields.io/badge/VS%20Code-1a1a1a?style=flat-square&logo=visualstudiocode&logoColor=white)

<br/>

---

<br/>

<div align="center">

```
┌──────────────────────────────────────────────┐
│  pipeline   : the-placement-arc              │
│  stage      : dsa-tests (running)            │
│  next_stage : core-cs                        │
│  deploy     : pending → offer_letter.json    │
│                                              │
│  this pipeline doesn't have a "fail" state.  │
│  only "not yet passing."                     │
└──────────────────────────────────────────────┘
```

<sub>15 builds · 15 green · 0 skipped jobs · runner pool: alpha-m</sub>

</div>
