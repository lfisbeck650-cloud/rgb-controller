# RGB Controller (Beta)

GTK3-GUI zur Steuerung der RGB-Beleuchtung einer **MEDION BEAST X25** Tastatur unter Linux.

> **Hinweis:** Dies ist die **erste Beta-Version**. Es gibt noch keine Garantie,
> dass alles funktioniert – Bugs sind willkommen als Issue.

## Features

- Farbe für alle 7 Lichtzonen gleichzeitig wählen
- Muster (Solid, Breathing, Wave, Blinking, Flow) über die API setzen
- Kommunikation direkt per HID-Feature-Report über `/dev/hidraw1`

## Installation

```sh
sudo dpkg -i rgb-controller_1.0.0_amd64.deb
```

Danach im Anwendungsmenü „RGB Controller“ starten oder `rgb-controller` im Terminal.

## Bauen aus dem Quellcode

```sh
make
```

Benötigt: `gcc`, `make`, `libgtk-3-dev`, `pkg-config`.

## Einschränkungen (Beta)

- Device-Pfad ist fest `/dev/hidraw1` (evtl. Root-Rechte nötig)
- Nur ein Farbbutton in der UI, Musterwahl folgt später

## Lizenz

Siehe Repository.
