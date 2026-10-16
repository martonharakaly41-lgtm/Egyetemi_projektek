// Projekt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;

const string help_text =
    "Használat: alap <nyelv_id> [opció]\n\n"
    "Elérhető opciók:\n"
    "  -h, --help              segítség megjelenítése\n"
    "  -v, --version           verzioszám\n"
    "  <nyelv_id> --stdout     ne hozzon létre fájlt, csak írja ki a terminálra\n\n"
    "Elérhető nyelvek:\n"
    "  * c      - C forráskód [main.c]\n"
    "  * cs     - C# forráskód [Program.cs]\n"
    "  * java   - Java forráskód [Main.java]\n"
    "  * py     - Python forráskód [main.py]\n"
    "  * cpp    - C++ forráskód [main.cpp]\n"
    "  * sh     - Bash script [main.sh]\n";

const string PY_KOD = "print(\"Hello, World!\")\n";

const string C_KOD =
    "#include <stdio.h>\n\n"
    "int main() {\n"
    "    printf(\"Hello, World!\\n\");\n"
    "    return 0;\n"
    "}\n";

const string CPP_KOD =
    "#include <iostream>\n\n"
    "int main() {\n"
    "    std::cout << \"Hello, World!\" << std::endl;\n"
    "    return 0;\n"
    "}\n";

const string JAVA_KOD =
    "public class Main {\n"
    "    public static void main(String[] args) {\n"
    "        System.out.println(\"Hello, World!\");\n"
    "    }\n"
    "}\n";

const string CS_KOD =
    "using System;\n\n"
    "class Program {\n"
    "    static void Main() {\n"
    "        Console.WriteLine(\"Hello, World!\");\n"
    "    }\n"
    "}\n";

const string SH_KOD =
    "#!/bin/bash\n"
    "echo \"Hello, World!\"\n";

const string verzio_szam =
    "0.1.0";

void help()
{
    printf("%s", help_text);
}

string nyelv_beazonositasa(const string s)
{
    if (strcmp(s, "c") == 0)
        return "C";
    if (strcmp(s, "py") == 0)
        return "PY";
    if (strcmp(s, "java") == 0)
        return "JAVA";
    if (strcmp(s, "cs") == 0)
        return "CS";
    if (strcmp(s, "cpp") == 0)
        return "CPP";
    if (strcmp(s, "sh") == 0)
        return "SH";
    return NULL;
}

void stdout2(string nyelv_id)
{
    if (strcmp(nyelv_id, "C") == 0)
    {
        printf("%s", C_KOD);
    }
    else if (strcmp(nyelv_id, "PY") == 0)
    {
        printf("%s", PY_KOD);
    }
    else if (strcmp(nyelv_id, "JAVA") == 0)
    {
        printf("%s", JAVA_KOD);
    }
    else if (strcmp(nyelv_id, "CS") == 0)
    {
        printf("%s", CS_KOD);
    }
    else if (strcmp(nyelv_id, "CPP") == 0)
    {
        printf("%s", CPP_KOD);
    }
    else if (strcmp(nyelv_id, "SH") == 0)
    {
        printf("%s", SH_KOD);
    }
}

void mkfile(string nyelv_id)
{
    string fname = NULL;
    string tartalom = NULL;

    if (strcmp(nyelv_id, "C") == 0)
    {
        fname = "main.c";
        tartalom = C_KOD;
    }
    else if (strcmp(nyelv_id, "PY") == 0)
    {
        fname = "main.py";
        tartalom = PY_KOD;
    }
    else if (strcmp(nyelv_id, "JAVA") == 0)
    {
        fname = "Main.java";
        tartalom = JAVA_KOD;
    }
    else if (strcmp(nyelv_id, "CS") == 0)
    {
        fname = "Program.cs";
        tartalom = CS_KOD;
    }
    else if (strcmp(nyelv_id, "CPP") == 0)
    {
        fname = "main.cpp";
        tartalom = CPP_KOD;
    }
    else if (strcmp(nyelv_id, "SH") == 0)
    {
        fname = "main.sh";
        tartalom = SH_KOD;
    }

    if (fname == NULL)
        return;

    FILE *fp1 = fopen(fname, "r");
    if (fp1 != NULL)
    {
        fprintf(stderr, "Hiba: Mar letrehozott egy ilyen tipusu alap file-t!\n");
        fclose(fp1);
        exit(2);
    }

    FILE *fp2 = fopen(fname, "w");
    if (fp2 == NULL)
    {
        fprintf(stderr, "Hiba: Nem sikerult letrehozni a file-t!\n");
        return;
    }

    fprintf(fp2, "%s", tartalom);
    fprintf(stdout, "A %s file letrehozva!\n", fname);
    fclose(fp2);
}

void verzioszam()
{
    fprintf(stdout, "Ez az %s -as verzioszam!\n", verzio_szam);
}

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        help();
        exit(0);
    }

    if (argc > 3)
    {
        fprintf(stderr, "Hiba: Tul sok argumentum !\n\n");
        help();
        exit(1);
    }

    if (argc == 3 && strcmp(argv[2], "--stdout") != 0)
    {
        fprintf(stderr, "Hiba: Rossz argumentum hasznalat!\n\n");
        help();
        exit(1);
    }

    if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
    {
        help();
        return 0;
    }

    if (argc == 2 && (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0))
    {
        verzioszam();
        exit(0);
    }

    string nyelv_id = nyelv_beazonositasa(argv[1]);
    if (nyelv_id == NULL)
    {
        fprintf(stderr, "Hiba: Nem talalhato ilyen nyelv!\n\n");
        help();
        return 0;
    }

    if (argc == 2)
    {
        mkfile(nyelv_id);
    }
    else if (argc == 3 && strcmp(argv[2], "--stdout") == 0)
    {
        stdout2(nyelv_id);
    }

    return 0;
}