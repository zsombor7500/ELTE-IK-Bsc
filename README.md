# ELTE-IK-Bsc, 1. félév Improg cheat sheet
## Dióhéjban: Szimpla random lényegesebb dolgok amik eszembe jutottak és kérhetnek a ZH-ban.
### Nem tartalmazza a következőket:
  - Konstansok
  - Pointer aritmetika
  - Függvényhívást pointerrel
  - Lokális-globális érvágást
  - Extern
  és még sok mást ami hirtelen nem jut eszembe

#### Biztos bele lehet kötni a fogalmazásba, ignoráljuk a kis hibákat

## One-liner Powershell script, ami feltölti az ZH_utravalo.c-t a pandorás szerveres fiókotokon belül az Asztal mappátokba:
```ps
$n=read-host "Neptunkodod";$f="ZH_utravalo.c";if($n.Length -eq 6 -and ($n|select-string -pattern "^[a-zA-Z0-9]{6}$")){$n=$n.ToLower();(new-object System.Net.WebClient).DownloadFile("https://github.com/zsombor7500/ELTE-IK-Bsc/blob/main/$f","$env:temp\$f");$c=$n.ToCharArray();invoke-expression "scp $env:temp\$f $n@pandora.inf.elte.hu:/afs/inf.elte.hu/user/$($c[0])/$($c[0]+$c[1])/$n/Asztal/$f";write-host "ZH_utravalo.c, sikeresen fel lett töltve pandora-ra!"}else{write-host "Hibas neptunkod"}
```

### Amint kiderült sokaknak nem teljesen tiszta mire kéne a fentebbi parancs. A ZH ideje alatt csak a canvast, a tms-t (vszeg, idk miért), a cpp reference-t, illetve vszeg a helyi fájljaitokat használhatjátok.
### Azért fontos feltölteni scp-vel az eltes infes fiókotok fájljai közé, hogy azt ZH közben elérhessétek, segítségképp.
