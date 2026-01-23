#!/usr/bin/env bash

set -e

rm -rf _site
mkdir -p _site/slides


for typ_file in $(find . -name "slides.typ" -not -path "./.git/*" -not -path "./.cache/*" -not -path "./_site/*"); do
  dir=$(dirname "$typ_file")
  topic=$(basename "$dir")

  echo "  → $topic"

  mkdir -p "_site/slides/$topic"

  find "$dir" -type f \( -name "*.png" -o -name "*.jpg" -o -name "*.jpeg" -o -name "*.svg" \) -exec cp {} "_site/slides/$topic/" \; 2>/dev/null || true

  typst compile "$typ_file" "_site/slides/$topic/slides.pdf"
done


cat > _site/index.html << 'EOF'
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>DSA-S26 | IIITH</title>
  <style>
    body {
      font-family: 'Fira Sans', system-ui, -apple-system, sans-serif;
      line-height: 1.6;
      max-width: 800px;
      margin: 0 auto;
      padding: 2rem 1rem;
      color: #23373b;
      background: #fafafa;
    }
    header {
      border-bottom: 2px solid #23373b;
      padding-bottom: 1rem;
      margin-bottom: 2rem;
    }
    h1 {
      margin: 0;
      font-size: 2rem;
      font-weight: 300;
      color: #23373b;
    }
    .subtitle {
      color: #666;
      font-size: 0.9rem;
      margin-top: 0.25rem;
    }
    h2 {
      font-size: 1.5rem;
      font-weight: 300;
      margin-top: 2rem;
      color: #23373b;
    }
    a {
      color: #23373b;
      text-decoration: none;
      border-bottom: 1px solid #ddd;
      transition: border-color 0.2s;
    }
    a:hover {
      border-bottom-color: #23373b;
    }
    .slide-container {
      margin: 2rem 0;
      border: 1px solid #ddd;
      background: white;
    }
    iframe {
      width: 100%;
      height: 600px;
      border: none;
      display: block;
    }
    footer {
      margin-top: 3rem;
      padding-top: 1rem;
      border-top: 1px solid #ddd;
      font-size: 0.9rem;
      color: #666;
    }
  </style>
</head>
<body>
  <header>
    <h1>DSA Tutorial Series</h1>
    <p class="subtitle">IIITH Spring 2026</p>
  </header>

  <main>
    <h2>Sorting Algorithms</h2>
    <div class="slide-container">
      <iframe src="slides/sorting/slides.pdf"></iframe>
    </div>
    <p><a href="slides/sorting/slides.pdf" download>Download PDF</a></p>

    <h2>Stacks and Queues</h2>
    <div class="slide-container">
      <iframe src="slides/stacks-and-queues/slides.pdf"></iframe>
    </div>
    <p><a href="slides/stacks-and-queues/slides.pdf" download>Download PDF</a></p>

    <h2>Trees</h2>
    <div class="slide-container">
      <iframe src="slides/trees/slides.pdf"></iframe>
    </div>
    <p><a href="slides/trees/slides.pdf" download>Download PDF</a></p>
  </main>

  <footer>
    <p>Data Structures and Algorithms · IIITH 2026</p>
  </footer>
</body>
</html>
EOF

echo "   cd _site && python -m http.server 8000"
