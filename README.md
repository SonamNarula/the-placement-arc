<!-- SONAM NARULA · 23BCON0190 · JECRC UNIVERSITY · CRT 2026 -->

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=rect&color=0:1c1c1e,50:2c2c2e,100:3a3a3c&height=180&section=header&text=THE%20PLACEMENT%20ARC&fontSize=40&fontColor=e5e5ea&animation=fadeIn&fontAlignY=45&desc=CSE%206M%202027%20%C2%B7%20CRT%202026%20%C2%B7%20one%20deploy%20target%3A%20the%20offer&descSize=13&descAlignY=68&descColor=636366" />

### still compiling. one day at a time.

[![Typing SVG](https://readme-typing-svg.demolab.com?font=JetBrains+Mono&weight=600&size=14&pause=2200&color=8E8E93&center=true&vCenter=true&width=750&height=30&lines=batches+change.+the+routine+doesn%27t.;confidence%3A+compiled+successfully.;sixteen+tests+logged.+zero+skipped.;one+deploy+target%3A+offer_letter.json.)](https://git.io/typing-svg)

**Sonam Narula** · B.Tech CSE '27 · JECRC University

<br/>

![pipeline](https://img.shields.io/badge/pipeline-passing-e5e5ea?style=flat-square&logo=githubactions&logoColor=1c1c1e&labelColor=2c2c2e)
&nbsp;![batch](https://img.shields.io/badge/batch-6m%20%E2%86%92%20alpha--m-e5e5ea?style=flat-square&labelColor=2c2c2e)
&nbsp;![builds](https://img.shields.io/badge/builds-16%2F16_green-e5e5ea?style=flat-square&labelColor=2c2c2e)
&nbsp;![coverage](https://img.shields.io/badge/coverage-94.8%25-e5e5ea?style=flat-square&labelColor=2c2c2e)
&nbsp;![day](https://img.shields.io/badge/day-083-e5e5ea?style=flat-square&labelColor=2c2c2e)

<sub>pool upgraded to alpha-m — top tier, no rank above it. target unchanged: offer_letter.json.</sub>

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
  runner_pool: alpha-m          # promoted from standard-6m. still not the target.
  current_stage: dsa-tests
  day: 83
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
  to     : alpha-m            (top tier — no pool ranks above this one)
  reason : 15 consecutive green builds
           mean coverage 94.4%
           3 builds at 100% coverage

[2026-06-21 06:15]  EVENT  build.recorded
  job    : G1 CBT-1 — Arrays
  result : 50 / 50, 100.0% coverage
  streak : 16 consecutive green builds
           4 builds at 100% coverage

note: runner pools aren't requested. they're computed
      from build history on every push. this one ran
      the numbers and moved itself to the top tier.

      that's the ceiling on tiers. it was never the
      ceiling on goals. the deploy target hasn't moved.
      it never was "alpha-m." it's still offer_letter.json.
```

<br/>

```
┌──────────────────────────────────────────────────────────┐
│  LESSON LOGGED                                           │
│                                                          │
│  alpha-m is the top batch. there's no tier above it.     │
│  and it still isn't the finish line.                     │
│                                                          │
│  batches are checkpoints. they don't get a victory lap.  │
│  the only deploy that counts is the offer letter.        │
└──────────────────────────────────────────────────────────┘
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
# alpha-m wasn't granted by anyone. it was computed, and the
# config doesn't treat it as an achievement field.

# there's no retry_limit set on effort here. only on patience,
# and that's still being tuned.

# one test score is a sample size of one. sixteen green builds
# in a row, averaging 94.8%, is a distribution you can trust.

# the only failure mode this pipeline actually has is the
# quiet kind — the one where it just stops running. that
# hasn't happened in 83 days, and it isn't scheduled to.

# being the loudest build in the room was never the goal.
# being the one still running when review starts was.

# top tier is still just a tier. it doesn't deploy anything
# on its own. the offer letter does that, or nothing does.
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
| `#016` | 21 Jun 2026 | [G1 CBT-1 — Arrays](./G1%20CBT-1.png) | 50 / 50 | 100.0% | **PASS ★** |

<br/>

---

<br/>

## build environment

![C++](https://img.shields.io/badge/C%2B%2B-2c2c2e?style=flat-square&logo=cplusplus&logoColor=e5e5ea)
&nbsp;![Git](https://img.shields.io/badge/Git-2c2c2e?style=flat-square&logo=git&logoColor=e5e5ea)
&nbsp;![GitHub](https://img.shields.io/badge/GitHub-2c2c2e?style=flat-square&logo=github&logoColor=e5e5ea)
&nbsp;![VS Code](https://img.shields.io/badge/VS%20Code-2c2c2e?style=flat-square&logo=visualstudiocode&logoColor=e5e5ea)

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

<sub>16 builds · 16 green · 0 skipped jobs · runner pool: alpha-m</sub>

<br/>

<img src="https://capsule-render.vercel.app/api?type=rect&color=0:3a3a3c,50:2c2c2e,100:1c1c1e&height=60&section=footer&animation=fadeIn" />

</div>
