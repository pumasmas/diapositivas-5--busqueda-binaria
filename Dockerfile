FROM debian:stable-slim

# Install reasons:
# - python3-pygments: Required by minted (python3 in texlive-latex-extra)
# - wget, curl, xz-utils, tar, ca-certificates: For tlmgr install
# - perl, ghostscript: Required for LaTeX tools
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        wget curl xz-utils tar ca-certificates \
        perl python3-pygments ghostscript \
        libfontconfig1 \
        && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /latexstuff
WORKDIR /latexstuff

RUN mkdir -p /latexstuff
WORKDIR /latexstuff

RUN ARCH=$(uname -m) && \
    if [ "$ARCH" = "x86_64" ]; then TEXARCH="x86_64-linux"; else TEXARCH="aarch64-linux"; fi && \
    echo "selected_scheme scheme-basic" > texlive.profile && \
    echo "TEXDIR /usr/local/texlive/current" >> texlive.profile && \
    echo "TEXMFCONFIG ~/.texlive2024/texmf-config" >> texlive.profile && \
    echo "TEXMFVAR ~/.texlive2024/texmf-var" >> texlive.profile && \
    echo "binary_$TEXARCH 1" >> texlive.profile && \
    echo "option_doc 0" >> texlive.profile && \
    echo "option_src 0" >> texlive.profile && \
    echo "option_autobackup 0" >> texlive.profile && \
    echo "option_path 0" >> texlive.profile

RUN wget https://ftp.math.utah.edu/pub/tex/historic/systems/texlive/2024/tlnet-final/install-tl-unx.tar.gz \
    && tar -xzf install-tl-unx.tar.gz \
    && cd install-tl-* \
    && ./install-tl --profile=/latexstuff/texlive.profile \
         --repository https://ftp.math.utah.edu/pub/tex/historic/systems/texlive/2024/tlnet-final

ENV PATH="/usr/local/texlive/current/bin/x86_64-linux:/usr/local/texlive/current/bin/aarch64-linux:${PATH}"

RUN tlmgr update --self && \
    tlmgr install latexmk sourcesanspro microtype babel-spanish graphics xcolor \
    xstring etoolbox minted fontawesome5 tcolorbox amsmath amsfonts mathtools \
    hyperref pgf beamer xkeyval upquote lineno pdfcol listings listingsutf8 \
    float ly1 tikzfill qrcode

WORKDIR /app

