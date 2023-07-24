# C/Lua Task

1) Klíč se skládá z řetězce dotazu a názvu hosta zadaného v dotazu. V případě potřeby můžeme pomocí direktivy proxy_cache_key zadat vlastní formát klíče. Výchozí formát je následující `Proxy_cache_key $scheme$proxy_host$uri$is_args$args;`
Klíč slouží k vyhledání souboru v cache. Pokud je soubor v cachi nalezen, vrátí jej nginx klientovi, v opačném případě jej nginx načte ze zdrojového serveru a poté jej uloží do paměti.
Umístění souboru v cachi lze určit pomocí direktivy `proxy_cache_path`. Samotné cache je uloženo v souborech, jejichž názvy jsou generovány pomocí šifrovaného klíče MD5.
Operační systém ukládá cache také do souborů, ale může používat jiná schémata ukládání, bez ohledu na strukturu používanou samotným systémem nginx

2) Pomocí funkce nginx nemůžeme předem vytvořit klíč pro další přenos v hlavičce. Jediné, co můžeme udělat, je vytvořit proměnnou, která opakuje strukturu klíče. Pomocí direktivy `set` můžeme vytvořit proměnnou, ve které můžeme kombinovat hodnoty z formátu klíče. Pak můžeme pomocí modulu `ngx_http_headers_module` přidat hlavičku `X-Cache-Key` pomocí direktivy `add_header` a přidat do ní hodnotu dříve vytvořené proměnné.  

3) Tento problém jsem vyřešil pomocí datové struktury trie (prefixový strom), která je ideální pro hledání vzorů v řetězcích. Při vkládání vzorů do trie obsahuje každý uzel jeden znak a jeho potomci představují možné další znaky. 
Trie se pro tuto úlohu dobře hodí, protože doba hledání nezávisí na počtu záznamů, ale je určena pouze délkou hledaného řetězce. 
Mezi další možná řešení, rovněž založená na trie, patří možnost zapisovat do uzlů nikoli jednotlivé znaky, ale jednotlivé části adresy oddělené tečkami. Tento přístup by mohl zjednodušit proces vyhledávání, ale zároveň výrazně zvýšit objem použité paměti. V mé implementaci může mít každý uzel určitý maximální počet potomků (všechny možné znaky). Při druhém přístupu by však bylo nutné vytvořit obrovské množství uzlů pro různé kombinace znaků.
Alternativně by bylo možné použít hashovací tabulky, které mohou rovněž zajistit srovnatelnou rychlost vyhledávání. V tomto případě však vznikají problémy s kolizí a složitostí vyhledávání.
Hlavním problémem bylo zajištění stabilního vyhledávání vzorů s různým umístěním znaku "*". 
Mezi možné oblasti dalšího zlepšení patří optimalizace vyhledávacích algoritmů a efektivnější ukládání záznamů ve struktuře.
Většina času byla věnována ladění a podrobnému prostudování teoretických aspektů problému a použité datové struktury.

# Problem – CDN DNS

  Při řešení problému jsem zvolil datovou strukturu, která je pro směrování nejvhodnější - prefixový strom (trie). V tomto problému poskytuje prefixový strom rychlé vyhledávání díky tomu, že počet operací je omezen délkou prefixu.
Po vyřešení předchozího problému nebyly při řešení tohoto problému žádné kritické problémy, protože pro efektivní řešení je možné použít podobnou strukturu.
Dalším přístupem mohlo být použití jiné datové struktury, například hašovací tabulky nebo binárního vyhledávacího stromu, nicméně prefixový strom je efektivnějším řešením pro směrování na základě prefixů, protože poskytuje jednodušší vyhledávací algoritmus, menší spotřebu paměti a podporuje vysokou rychlost vyhledávání.
Tato struktura je ideální pro další škálování, protože umožňuje poměrně snadno ukládat velké množství záznamů.
Pro zlepšení implementace je možné strukturu prefixového stromu optimalizovat, například komprimovat cesty nebo použít vyvažovací algoritmy pro snížení hloubky stromu
Tato úloha zabrala mnohem méně času díky včasnému seznámení se s teorií a obeznámení se s implementací takového algoritmu.
