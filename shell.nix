{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    typst
    python3
  ];

  shellHook = ''
    echo "DSA-S26 Build Environment"
    echo ""
    echo "Usage:"
    echo "  ./build-site.sh          "
    echo "  cd _site && python -m http.server 8000"
    echo ""
  '';
}
