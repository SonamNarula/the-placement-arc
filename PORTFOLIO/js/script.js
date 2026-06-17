/**
 * SONAM NARULA PORTFOLIO — script.js
 * ════════════════════════════════════
 * Features:
 *  - Custom cursor with hover states
 *  - Loading animation with terminal boot sequence
 *  - Particle canvas background
 *  - Typed text animation
 *  - Counter animations (hero stats)
 *  - Scroll-driven reveal (Intersection Observer)
 *  - Skill bar fill on scroll
 *  - Magnetic button effect
 *  - Tilt effect on cards
 *  - Project modal system
 *  - Interactive terminal emulator
 *  - Developer mode toggle
 *  - Dark / Light mode toggle (LocalStorage)
 *  - Ripple effect on buttons
 *  - Scroll progress indicator
 *  - Konami code Easter egg
 *  - Navbar scroll behaviour
 */

'use strict';

/* ────────────────────────────────────────────────────────────
   UTILS
──────────────────────────────────────────────────────────── */
const $ = (s, p = document) => p.querySelector(s);
const $$ = (s, p = document) => [...p.querySelectorAll(s)];

function lerp(a, b, t) { return a + (b - a) * t; }

function clamp(v, min, max) { return Math.max(min, Math.min(max, v)); }

/* ────────────────────────────────────────────────────────────
   LOADER
──────────────────────────────────────────────────────────── */
(function initLoader() {
  const loader = $('#loader');
  const pct    = $('#loader-pct');
  const start  = Date.now();
  const dur    = 3000; // ms

  function tick() {
    const progress = Math.min((Date.now() - start) / dur, 1);
    pct.textContent = Math.round(progress * 100) + '%';
    if (progress < 1) { requestAnimationFrame(tick); return; }
    setTimeout(() => {
      loader.classList.add('hidden');
      document.body.style.overflow = '';
      initAll(); // start everything after load
    }, 400);
  }

  document.body.style.overflow = 'hidden';
  requestAnimationFrame(tick);
})();

/* ────────────────────────────────────────────────────────────
   INIT ALL
──────────────────────────────────────────────────────────── */
function initAll() {
  initCursor();
  initScrollProgress();
  initNavbar();
  initMobileMenu();
  initParticles();
  initTyped();
  initCounters();
  initReveal();
  initSkillBars();
  initMagneticButtons();
  initTiltCards();
  initTerminal();
  initDevMode();
  initTheme();
  initContactForm();
  initRipple();
  initKonami();
}

/* ────────────────────────────────────────────────────────────
   CUSTOM CURSOR
──────────────────────────────────────────────────────────── */
function initCursor() {
  const dot  = $('#cursor-dot');
  const ring = $('#cursor-ring');
  let mx = window.innerWidth / 2, my = window.innerHeight / 2;
  let rx = mx, ry = my;

  document.addEventListener('mousemove', e => { mx = e.clientX; my = e.clientY; });

  function tick() {
    // Dot follows instantly
    dot.style.left  = mx + 'px';
    dot.style.top   = my + 'px';
    // Ring lags slightly
    rx = lerp(rx, mx, 0.14);
    ry = lerp(ry, my, 0.14);
    ring.style.left = rx + 'px';
    ring.style.top  = ry + 'px';
    requestAnimationFrame(tick);
  }
  requestAnimationFrame(tick);

  // Hover states
  const hoverEls = 'a, button, input, textarea, .skill-card, .project-card, .timeline-item';
  document.addEventListener('mouseover', e => {
    if (e.target.closest(hoverEls)) document.body.classList.add('cursor-hover');
  });
  document.addEventListener('mouseout', e => {
    if (e.target.closest(hoverEls)) document.body.classList.remove('cursor-hover');
  });
}

/* ────────────────────────────────────────────────────────────
   SCROLL PROGRESS
──────────────────────────────────────────────────────────── */
function initScrollProgress() {
  const bar = $('#scroll-progress');
  window.addEventListener('scroll', () => {
    const max = document.documentElement.scrollHeight - window.innerHeight;
    bar.style.width = (window.scrollY / max * 100) + '%';
  }, { passive: true });
}

/* ────────────────────────────────────────────────────────────
   NAVBAR
──────────────────────────────────────────────────────────── */
function initNavbar() {
  const nav = $('#navbar');
  window.addEventListener('scroll', () => {
    nav.classList.toggle('scrolled', window.scrollY > 60);
  }, { passive: true });
}

/* ────────────────────────────────────────────────────────────
   MOBILE MENU
──────────────────────────────────────────────────────────── */
function initMobileMenu() {
  const btn  = $('#hamburger');
  const menu = $('#mobile-menu');
  btn.addEventListener('click', () => {
    menu.classList.toggle('open');
  });
}
function closeMobile() { $('#mobile-menu').classList.remove('open'); }

/* ────────────────────────────────────────────────────────────
   PARTICLE CANVAS
──────────────────────────────────────────────────────────── */
function initParticles() {
  const canvas = $('#particles-canvas');
  if (!canvas) return;
  const ctx    = canvas.getContext('2d');
  const isDark = !document.body.classList.contains('light');

  let W, H, particles = [], mouse = { x: null, y: null };

  function resize() {
    W = canvas.width  = canvas.offsetWidth;
    H = canvas.height = canvas.offsetHeight;
  }
  window.addEventListener('resize', resize, { passive: true });
  resize();

  // Create particles
  function spawn(n) {
    particles = [];
    for (let i = 0; i < n; i++) {
      particles.push({
        x:  Math.random() * W,
        y:  Math.random() * H,
        vx: (Math.random() - 0.5) * 0.3,
        vy: (Math.random() - 0.5) * 0.3,
        r:  Math.random() * 1.5 + 0.5,
        a:  Math.random(),
      });
    }
  }
  spawn(70);

  canvas.addEventListener('mousemove', e => {
    const r = canvas.getBoundingClientRect();
    mouse.x = e.clientX - r.left;
    mouse.y = e.clientY - r.top;
  });
  canvas.addEventListener('mouseleave', () => { mouse.x = mouse.y = null; });

  function draw() {
    ctx.clearRect(0, 0, W, H);

    const color = getComputedStyle(document.body).getPropertyValue('--primary').trim() || '#00e5ff';

    particles.forEach(p => {
      // Mouse repulsion
      if (mouse.x !== null) {
        const dx = p.x - mouse.x, dy = p.y - mouse.y;
        const dist = Math.sqrt(dx * dx + dy * dy);
        if (dist < 120) {
          p.vx += dx / dist * 0.08;
          p.vy += dy / dist * 0.08;
        }
      }
      p.vx *= 0.98; p.vy *= 0.98;
      p.x += p.vx; p.y += p.vy;
      // Wrap
      if (p.x < 0) p.x = W; if (p.x > W) p.x = 0;
      if (p.y < 0) p.y = H; if (p.y > H) p.y = 0;

      ctx.beginPath();
      ctx.arc(p.x, p.y, p.r, 0, Math.PI * 2);
      ctx.fillStyle = color.replace(')', `,${p.a * 0.6})`).replace('rgb', 'rgba');
      ctx.fill();
    });

    // Draw connections
    for (let i = 0; i < particles.length; i++) {
      for (let j = i + 1; j < particles.length; j++) {
        const dx = particles[i].x - particles[j].x;
        const dy = particles[i].y - particles[j].y;
        const d  = Math.sqrt(dx * dx + dy * dy);
        if (d < 100) {
          ctx.beginPath();
          ctx.moveTo(particles[i].x, particles[i].y);
          ctx.lineTo(particles[j].x, particles[j].y);
          ctx.strokeStyle = `rgba(0,229,255,${(1 - d / 100) * 0.08})`;
          ctx.lineWidth = 0.5;
          ctx.stroke();
        }
      }
    }

    requestAnimationFrame(draw);
  }
  draw();
}

/* ────────────────────────────────────────────────────────────
   TYPED TEXT
──────────────────────────────────────────────────────────── */
function initTyped() {
  const el = $('#typed-text');
  if (!el) return;
  const lines = [
    'Aspiring software developer from Jaipur, India.',
    'Building the web, one commit at a time.',
    '200+ day coding streak and counting.',
    'C++ + DSA + Web Dev — the full picture.',
    'Not here to impress. Here to build.',
  ];
  let line = 0, char = 0, deleting = false;

  function tick() {
    const current = lines[line];
    if (!deleting) {
      el.textContent = current.slice(0, ++char);
      if (char === current.length) { deleting = true; setTimeout(tick, 2200); return; }
    } else {
      el.textContent = current.slice(0, --char);
      if (char === 0) {
        deleting = false;
        line = (line + 1) % lines.length;
      }
    }
    setTimeout(tick, deleting ? 30 : 55);
  }
  setTimeout(tick, 1800);
}

/* ────────────────────────────────────────────────────────────
   COUNTER ANIMATIONS
──────────────────────────────────────────────────────────── */
function initCounters() {
  const targets = {
    'stat-streak':   200,
    'stat-problems': 150,
    'stat-commits':  300,
  };
  Object.entries(targets).forEach(([id, end]) => {
    const el = $('#' + id);
    if (!el) return;
    let start = 0;
    const dur = 1800, step = 16;
    const inc = end / (dur / step);
    const timer = setInterval(() => {
      start = Math.min(start + inc, end);
      el.textContent = Math.floor(start) + (start >= end ? '+' : '');
      if (start >= end) clearInterval(timer);
    }, step);
  });
}

/* ────────────────────────────────────────────────────────────
   SCROLL REVEAL — Intersection Observer
──────────────────────────────────────────────────────────── */
function initReveal() {
  const options = { threshold: 0.12, rootMargin: '0px 0px -40px 0px' };
  const obs = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
      if (!entry.isIntersecting) return;
      const el    = entry.target;
      const delay = el.dataset.delay ? parseInt(el.dataset.delay) : 0;
      setTimeout(() => el.classList.add('visible'), delay);
      obs.unobserve(el);
    });
  }, options);

  $$('.reveal, .reveal-left, .reveal-right').forEach(el => obs.observe(el));
}

/* ────────────────────────────────────────────────────────────
   SKILL BAR FILL
──────────────────────────────────────────────────────────── */
function initSkillBars() {
  const obs = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
      if (!entry.isIntersecting) return;
      const bar = entry.target.querySelector('.skill-bar-fill');
      if (bar) {
        const pct = bar.dataset.pct;
        setTimeout(() => { bar.style.width = pct + '%'; }, 300);
      }
      obs.unobserve(entry.target);
    });
  }, { threshold: 0.3 });

  $$('.skill-card').forEach(el => obs.observe(el));
}

/* ────────────────────────────────────────────────────────────
   MAGNETIC BUTTONS
──────────────────────────────────────────────────────────── */
function initMagneticButtons() {
  $$('.magnetic').forEach(el => {
    el.addEventListener('mousemove', e => {
      const rect = el.getBoundingClientRect();
      const cx   = rect.left + rect.width / 2;
      const cy   = rect.top  + rect.height / 2;
      const dx   = (e.clientX - cx) * 0.22;
      const dy   = (e.clientY - cy) * 0.22;
      el.style.transform = `translate(${dx}px, ${dy}px)`;
    });
    el.addEventListener('mouseleave', () => {
      el.style.transform = '';
    });
  });
}

/* ────────────────────────────────────────────────────────────
   TILT EFFECT on cards
──────────────────────────────────────────────────────────── */
function initTiltCards() {
  $$('.skill-card, .project-card').forEach(card => {
    card.addEventListener('mousemove', e => {
      const rect = card.getBoundingClientRect();
      const x    = e.clientX - rect.left;
      const y    = e.clientY - rect.top;
      const cx   = rect.width  / 2;
      const cy   = rect.height / 2;
      const rotX = (y - cy) / cy * -6;
      const rotY = (x - cx) / cx *  6;
      // Update CSS custom properties for radial glow position
      card.style.setProperty('--mx', (x / rect.width  * 100) + '%');
      card.style.setProperty('--my', (y / rect.height * 100) + '%');
      card.style.transform = `perspective(600px) rotateX(${rotX}deg) rotateY(${rotY}deg) translateY(-4px)`;
    });
    card.addEventListener('mouseleave', () => {
      card.style.transform = '';
    });
  });
}

/* ────────────────────────────────────────────────────────────
   RIPPLE EFFECT
──────────────────────────────────────────────────────────── */
function initRipple() {
  $$('.btn-primary, .btn-outline, .form-submit').forEach(el => {
    el.addEventListener('click', e => {
      const rect   = el.getBoundingClientRect();
      const ripple = document.createElement('span');
      ripple.className = 'ripple';
      ripple.style.cssText = `
        left:${e.clientX - rect.left}px;
        top:${e.clientY - rect.top}px;
        width:${Math.max(rect.width, rect.height)}px;
        height:${Math.max(rect.width, rect.height)}px;
        margin-left:-${Math.max(rect.width, rect.height) / 2}px;
        margin-top:-${Math.max(rect.width, rect.height) / 2}px;
      `;
      el.style.position = 'relative';
      el.style.overflow = 'hidden';
      el.appendChild(ripple);
      ripple.addEventListener('animationend', () => ripple.remove());
    });
  });
}

/* ────────────────────────────────────────────────────────────
   MODAL SYSTEM
──────────────────────────────────────────────────────────── */
function openModal(id) {
  const m = $('#modal-' + id);
  if (!m) return;
  m.classList.add('open');
  document.body.style.overflow = 'hidden';
}
function closeModal(id) {
  const m = $('#modal-' + id);
  if (!m) return;
  m.classList.remove('open');
  document.body.style.overflow = '';
}
function handleModalClick(e, id) {
  if (e.target === e.currentTarget) closeModal(id);
}
document.addEventListener('keydown', e => {
  if (e.key === 'Escape') {
    $$('.modal-overlay.open').forEach(m => {
      m.classList.remove('open');
      document.body.style.overflow = '';
    });
    closeEgg();
  }
});

/* ────────────────────────────────────────────────────────────
   TERMINAL EMULATOR
──────────────────────────────────────────────────────────── */
function initTerminal() {
  const body  = $('#terminal-body');
  const input = $('#terminal-input');
  if (!body || !input) return;

  const commands = {
    help: () => [
      { t:'out', txt:'Available commands:', cls:'highlight' },
      { t:'out', txt:'  about      — who is Sonam Narula?' },
      { t:'out', txt:'  skills     — list of technical skills' },
      { t:'out', txt:'  projects   — view project list' },
      { t:'out', txt:'  experience — career timeline' },
      { t:'out', txt:'  contact    — how to reach me' },
      { t:'out', txt:'  streak     — daily coding habit' },
      { t:'out', txt:'  clear      — wipe terminal' },
      { t:'out', txt:'  theme      — toggle dark/light mode' },
      { t:'out', txt:'  social     — links' },
      { t:'out', txt:'  secret     — ??? 👀' },
    ],
    about: () => [
      { t:'out', txt:'> Sonam Narula', cls:'highlight' },
      { t:'out', txt:'  Role     : Aspiring Software Developer' },
      { t:'out', txt:'  Location : Jaipur, Rajasthan, India 🇮🇳' },
      { t:'out', txt:'  Focus    : Web Development + DSA' },
      { t:'out', txt:'  Status   : Available for opportunities' },
      { t:'out', txt:'' },
      { t:'out', txt:'  "Not the loudest in the room — the one who ships."', cls:'gold' },
    ],
    skills: () => [
      { t:'out', txt:'> Technical Skills', cls:'highlight' },
      { t:'out', txt:'  HTML5 / CSS3       ████████░░  88%' },
      { t:'out', txt:'  JavaScript (ES6+)  ████████░░  80%' },
      { t:'out', txt:'  C++ / DSA          ███████░░░  75%' },
      { t:'out', txt:'  Problem Solving    ████████░░  82%' },
      { t:'out', txt:'  Git / GitHub       ███████░░░  72%' },
      { t:'out', txt:'  Discipline         ██████████  99%', cls:'gold' },
    ],
    projects: () => [
      { t:'out', txt:'> Projects (3)', cls:'highlight' },
      { t:'out', txt:'' },
      { t:'out', txt:'  [1] TaskFlow — To-Do App', cls:'accent' },
      { t:'out', txt:'      Stack: HTML, CSS, JS, LocalStorage' },
      { t:'out', txt:'' },
      { t:'out', txt:'  [2] Calculator — DOM Mastery', cls:'accent' },
      { t:'out', txt:'      Stack: HTML, CSS Grid, JS, Regex' },
      { t:'out', txt:'' },
      { t:'out', txt:'  [3] DSA Visualizer Concepts', cls:'accent' },
      { t:'out', txt:'      Stack: C++, OOP, STL, Templates' },
      { t:'out', txt:'' },
      { t:'out', txt:'  → github.com/SonamNarula' },
    ],
    experience: () => [
      { t:'out', txt:'> Timeline', cls:'highlight' },
      { t:'out', txt:'  2023 — First line of HTML written' },
      { t:'out', txt:'  2023 — JavaScript unlocked everything' },
      { t:'out', txt:'  2024 — 200+ day coding streak begins 🔥' },
      { t:'out', txt:'  2024 — C++ & DSA mastery started' },
      { t:'out', txt:'  2025 — Building real projects', cls:'gold' },
      { t:'out', txt:'  ???? — Financial independence through code', cls:'accent' },
    ],
    contact: () => [
      { t:'out', txt:'> Contact Information', cls:'highlight' },
      { t:'out', txt:'  Email    : sonamnarula2108@gmail.com' },
      { t:'out', txt:'  GitHub   : github.com/SonamNarula' },
      { t:'out', txt:'  LinkedIn : linkedin.com/in/sonam-narula-402a60285' },
      { t:'out', txt:'  Location : Jaipur, India' },
      { t:'out', txt:'' },
      { t:'out', txt:'  Open to: internships, freelance, collaborations' },
    ],
    streak: () => [
      { t:'out', txt:'> Coding Streak Status', cls:'highlight' },
      { t:'out', txt:'  Current streak  : 200+ days 🔥', cls:'gold' },
      { t:'out', txt:'  Daily target    : code every single day' },
      { t:'out', txt:'  Days missed     : 0' },
      { t:'out', txt:'  Motivation      : discipline > motivation' },
      { t:'out', txt:'' },
      { t:'out', txt:'  "Motivation is unreliable. Discipline is a choice."' },
    ],
    social: () => [
      { t:'out', txt:'> Social Links', cls:'highlight' },
      { t:'out', txt:'  GitHub   → github.com/SonamNarula' },
      { t:'out', txt:'  LinkedIn → linkedin.com/in/sonam-narula-402a60285' },
      { t:'out', txt:'  Email    → sonamnarula2108@gmail.com' },
    ],
    theme: () => {
      toggleTheme();
      return [{ t:'out', txt:'> Theme toggled!', cls:'highlight' }];
    },
    secret: () => {
      setTimeout(() => showEasterEgg(), 500);
      return [
        { t:'out', txt:'> Initiating secret protocol...', cls:'gold' },
        { t:'out', txt:'  ████████████ 100%' },
        { t:'out', txt:'  Launching Easter egg...' },
      ];
    },
    clear: () => {
      setTimeout(() => { body.innerHTML = ''; }, 10);
      return [];
    },
  };

  function addLine(t, txt, cls) {
    const line = document.createElement('div');
    line.className = 'terminal-line';
    if (t === 'cmd') {
      line.innerHTML = `<span class="t-prompt">sonam@portfolio:~$</span><span class="t-cmd"> ${escHtml(txt)}</span>`;
    } else {
      line.innerHTML = `<span class="t-out ${cls || ''}">${escHtml(txt)}</span>`;
    }
    body.appendChild(line);
    body.scrollTop = body.scrollHeight;
  }

  function escHtml(s) {
    return s.replace(/&/g,'&amp;').replace(/</g,'&lt;').replace(/>/g,'&gt;');
  }

  function run(cmd) {
    const key = cmd.trim().toLowerCase();
    addLine('cmd', cmd);
    const fn = commands[key];
    if (fn) {
      const lines = fn() || [];
      lines.forEach((l, i) => {
        setTimeout(() => addLine(l.t, l.txt, l.cls), i * 35);
      });
    } else if (key === '') {
      // blank — do nothing
    } else {
      addLine('out', `command not found: ${cmd}. Type 'help' for commands.`, 't-error');
    }
  }

  // Welcome message
  ['> Welcome to Sonam\'s portfolio terminal.', '> Type \'help\' to get started.'].forEach((t, i) =>
    setTimeout(() => addLine('out', t, 'highlight'), i * 200)
  );

  input.addEventListener('keydown', e => {
    if (e.key === 'Enter') {
      const val = input.value;
      input.value = '';
      run(val);
    }
  });

  // Click anywhere on terminal body to focus input
  $('#terminal-section').addEventListener('click', () => input.focus());

  // Command history
  const history = [];
  let histIdx = -1;
  input.addEventListener('keydown', e => {
    if (e.key === 'ArrowUp') {
      histIdx = Math.min(histIdx + 1, history.length - 1);
      input.value = history[histIdx] || '';
    }
    if (e.key === 'ArrowDown') {
      histIdx = Math.max(histIdx - 1, -1);
      input.value = histIdx === -1 ? '' : (history[histIdx] || '');
    }
    if (e.key === 'Enter' && input.value.trim()) {
      history.unshift(input.value);
      histIdx = -1;
    }
  });
}

/* ────────────────────────────────────────────────────────────
   DEVELOPER MODE
──────────────────────────────────────────────────────────── */
function initDevMode() {
  const btn = $('#dev-toggle');
  if (!btn) return;
  const stored = localStorage.getItem('sn_devmode') === 'true';
  if (stored) { document.body.classList.add('dev-mode'); btn.classList.add('active'); }

  btn.addEventListener('click', () => {
    const isActive = document.body.classList.toggle('dev-mode');
    btn.classList.toggle('active', isActive);
    localStorage.setItem('sn_devmode', isActive);
  });
}

/* ────────────────────────────────────────────────────────────
   THEME TOGGLE (Dark / Light)
──────────────────────────────────────────────────────────── */
function initTheme() {
  const btn = $('#theme-toggle');
  if (!btn) return;
  const stored = localStorage.getItem('sn_theme');
  if (stored === 'light') { document.body.classList.add('light'); btn.textContent = '🌙 DARK'; }

  btn.addEventListener('click', toggleTheme);
}

function toggleTheme() {
  const btn   = $('#theme-toggle');
  const light = document.body.classList.toggle('light');
  if (btn) btn.textContent = light ? '🌙 DARK' : '☀ LIGHT';
  localStorage.setItem('sn_theme', light ? 'light' : 'dark');
}

/* ────────────────────────────────────────────────────────────
   CONTACT FORM
──────────────────────────────────────────────────────────── */
function initContactForm() {
  const form    = $('#contact-form');
  const success = $('#form-success');
  if (!form) return;

  form.addEventListener('submit', e => {
    e.preventDefault();
    const btn = form.querySelector('.form-submit');
    btn.textContent = 'SENDING...';
    btn.classList.add('sending');

    // Simulate async send
    setTimeout(() => {
      btn.textContent = 'SENT ✓';
      form.reset();
      success.classList.add('show');
      setTimeout(() => {
        btn.textContent = 'SEND MESSAGE →';
        btn.classList.remove('sending');
        success.classList.remove('show');
      }, 4000);
    }, 1800);
  });
}

/* ────────────────────────────────────────────────────────────
   KONAMI CODE EASTER EGG
   ↑↑↓↓←→←→BA
──────────────────────────────────────────────────────────── */
function initKonami() {
  const code   = ['ArrowUp','ArrowUp','ArrowDown','ArrowDown','ArrowLeft','ArrowRight','ArrowLeft','ArrowRight','b','a'];
  let progress = 0;

  document.addEventListener('keydown', e => {
    if (e.key === code[progress]) {
      progress++;
      if (progress === code.length) { progress = 0; showEasterEgg(); }
    } else {
      progress = 0;
    }
  });
}

function showEasterEgg() {
  const egg    = $('#easter-egg');
  const matrix = $('#egg-matrix');
  if (!egg) return;

  // Generate matrix rain text
  const chars = '01アイウエオカキクケコSNSNSN⬡⚡✦';
  let rows = '';
  for (let r = 0; r < 8; r++) {
    let row = '';
    for (let c = 0; c < 60; c++) row += chars[Math.floor(Math.random() * chars.length)] + ' ';
    rows += row + '\n';
  }
  matrix.textContent = rows;
  egg.classList.add('show');
}

function closeEgg() {
  const egg = $('#easter-egg');
  if (egg) egg.classList.remove('show');
}

/* ────────────────────────────────────────────────────────────
   PARALLAX — hero grid moves with scroll
──────────────────────────────────────────────────────────── */
window.addEventListener('scroll', () => {
  const grid = $('#hero-grid');
  if (!grid) return;
  grid.style.transform = `translateY(${window.scrollY * 0.15}px)`;
}, { passive: true });

/* ────────────────────────────────────────────────────────────
   EXPOSE GLOBALS for inline onclick
──────────────────────────────────────────────────────────── */
window.openModal       = openModal;
window.closeModal      = closeModal;
window.handleModalClick= handleModalClick;
window.closeMobile     = closeMobile;
window.closeEgg        = closeEgg;
window.showEasterEgg   = showEasterEgg;
