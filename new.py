from reportlab.lib.pagesizes import A4
from reportlab.lib import colors
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.units import mm
from reportlab.platypus import (SimpleDocTemplate, Paragraph, Spacer, Table,
                                 TableStyle, HRFlowable, PageBreak, KeepTogether)
from reportlab.lib.enums import TA_CENTER, TA_LEFT, TA_JUSTIFY, TA_RIGHT

# ── palette ───────────────────────────────────────────────────────────────────
DEEP_NAVY   = colors.HexColor("#0a1628")
NAVY        = colors.HexColor("#1a2744")
MED_NAVY    = colors.HexColor("#1e3a5f")
ACCENT      = colors.HexColor("#1565c0")
LIGHT_BLUE  = colors.HexColor("#e8f4fd")
PALE_BLUE   = colors.HexColor("#f0f7ff")
TEAL        = colors.HexColor("#006064")
TEAL_LIGHT  = colors.HexColor("#e0f7fa")
ORANGE      = colors.HexColor("#e65100")
ORANGE_LIGHT= colors.HexColor("#fff3e0")
GREEN       = colors.HexColor("#1b5e20")
GREEN_LIGHT = colors.HexColor("#e8f5e9")
PURPLE      = colors.HexColor("#4a148c")
PURPLE_LIGHT= colors.HexColor("#f3e5f5")
RED         = colors.HexColor("#b71c1c")
GREY_DARK   = colors.HexColor("#424242")
GREY_MED    = colors.HexColor("#757575")
GREY_LIGHT  = colors.HexColor("#f5f5f5")
GREY_BORDER = colors.HexColor("#bdbdbd")
WHITE       = colors.white
BLACK       = colors.HexColor("#212121")
DIVIDER_CLR = colors.HexColor("#90caf9")
YELLOW_BG   = colors.HexColor("#fffde7")
AMBER       = colors.HexColor("#ff8f00")

W, H = A4
CONTENT_W = W - 36*mm

# ── document ──────────────────────────────────────────────────────────────────
doc = SimpleDocTemplate(
    "/home/claude/Multiprocessor_Architecture_Notes.pdf",
    pagesize=A4,
    rightMargin=18*mm, leftMargin=18*mm,
    topMargin=20*mm,   bottomMargin=18*mm,
)

# ── style factory ─────────────────────────────────────────────────────────────
def S(name, **kw):
    return ParagraphStyle(name, **kw)

COVER_H1  = S("CH1", fontSize=28, textColor=WHITE, fontName="Helvetica-Bold",
               alignment=TA_CENTER, leading=34, spaceAfter=6)
COVER_H2  = S("CH2", fontSize=16, textColor=colors.HexColor("#bbdefb"),
               fontName="Helvetica", alignment=TA_CENTER, leading=20, spaceAfter=4)
COVER_SUB = S("CSub", fontSize=11, textColor=colors.HexColor("#cfd8dc"),
               fontName="Helvetica", alignment=TA_CENTER, leading=15)

CH_TITLE  = S("ChTitle", fontSize=15, textColor=WHITE, fontName="Helvetica-Bold",
               leading=19, spaceBefore=4, spaceAfter=4)
SEC_TITLE = S("SecTitle", fontSize=13, textColor=NAVY, fontName="Helvetica-Bold",
               leading=16, spaceBefore=10, spaceAfter=3)
SUB_TITLE = S("SubTitle", fontSize=11, textColor=ACCENT, fontName="Helvetica-Bold",
               leading=14, spaceBefore=7, spaceAfter=2)
SUB2      = S("Sub2", fontSize=10.5, textColor=TEAL, fontName="Helvetica-Bold",
               leading=13, spaceBefore=5, spaceAfter=2)

BODY      = S("Body", fontSize=10, textColor=BLACK, fontName="Helvetica",
               leading=15, spaceBefore=3, spaceAfter=3, alignment=TA_JUSTIFY)
BODY_IND  = S("BodyInd", fontSize=10, textColor=BLACK, fontName="Helvetica",
               leading=15, spaceBefore=2, spaceAfter=2, alignment=TA_JUSTIFY,
               leftIndent=10)
EMPH      = S("Emph", fontSize=10, textColor=GREY_DARK, fontName="Helvetica-Oblique",
               leading=14, spaceBefore=2, spaceAfter=2, alignment=TA_JUSTIFY,
               leftIndent=8)
FORMULA   = S("Formula", fontSize=10.5, textColor=RED, fontName="Helvetica-Bold",
               leading=14, alignment=TA_CENTER, spaceBefore=5, spaceAfter=5)
CODE_S    = S("CodeS", fontSize=9, textColor=colors.HexColor("#1a237e"),
               fontName="Courier", leading=12, leftIndent=8)
NOTE_S    = S("NoteS", fontSize=9.5, textColor=GREEN, fontName="Helvetica-Oblique",
               leading=13, leftIndent=8)
WARN_S    = S("WarnS", fontSize=9.5, textColor=ORANGE, fontName="Helvetica-Bold",
               leading=13, leftIndent=8)
CAPTION   = S("Caption", fontSize=8.5, textColor=GREY_MED, fontName="Helvetica-Oblique",
               leading=11, alignment=TA_CENTER, spaceBefore=2, spaceAfter=4)

# ── flowable helpers ──────────────────────────────────────────────────────────
def sp(h=6): return Spacer(1, h)

def divider(color=DIVIDER_CLR, thickness=0.8):
    return HRFlowable(width="100%", thickness=thickness, color=color,
                      spaceAfter=3, spaceBefore=3)

def chapter_header(num, title, subtitle=""):
    inner = [[Paragraph(f"Chapter {num}", S("cn", fontSize=10, textColor=colors.HexColor("#90caf9"),
                         fontName="Helvetica", leading=13, alignment=TA_CENTER))],
             [Paragraph(title, CH_TITLE)]]
    if subtitle:
        inner.append([Paragraph(subtitle, S("cs", fontSize=10,
                     textColor=colors.HexColor("#cfd8dc"), fontName="Helvetica-Oblique",
                     leading=13, alignment=TA_CENTER))])
    tbl = Table(inner, colWidths=[CONTENT_W])
    tbl.setStyle(TableStyle([
        ("BACKGROUND",    (0,0),(-1,-1), DEEP_NAVY),
        ("TOPPADDING",    (0,0),(-1,-1), 10),
        ("BOTTOMPADDING", (0,0),(-1,-1), 10),
        ("LEFTPADDING",   (0,0),(-1,-1), 14),
        ("ALIGN",         (0,0),(-1,-1), "CENTER"),
    ]))
    return tbl

def section_bar(title, color=MED_NAVY):
    tbl = Table([[Paragraph(title, SEC_TITLE)]], colWidths=[CONTENT_W])
    tbl.setStyle(TableStyle([
        ("BACKGROUND",    (0,0),(-1,-1), LIGHT_BLUE),
        ("LINEBELOW",     (0,0),(-1,-1), 2.5, color),
        ("TOPPADDING",    (0,0),(-1,-1), 5),
        ("BOTTOMPADDING", (0,0),(-1,-1), 5),
        ("LEFTPADDING",   (0,0),(-1,-1), 10),
    ]))
    return tbl

def sub_bar(title, color=TEAL_LIGHT, text_color=TEAL):
    st = S("sb_inner", fontSize=11, textColor=text_color, fontName="Helvetica-Bold",
           leading=14, spaceBefore=0, spaceAfter=0)
    tbl = Table([[Paragraph(title, st)]], colWidths=[CONTENT_W])
    tbl.setStyle(TableStyle([
        ("BACKGROUND",  (0,0),(-1,-1), color),
        ("LINEBEFORE",  (0,0),(0,-1),  3.5, text_color),
        ("TOPPADDING",  (0,0),(-1,-1), 5),
        ("BOTTOMPADDING",(0,0),(-1,-1),5),
        ("LEFTPADDING", (0,0),(-1,-1), 10),
    ]))
    return tbl

def info_box(text, bg=YELLOW_BG, line_color=AMBER, label="📌 Note"):
    st = S("ib", fontSize=9.5, textColor=GREY_DARK, fontName="Helvetica",
           leading=13, alignment=TA_JUSTIFY)
    tbl = Table([[Paragraph(f"<b>{label}:</b>  {text}", st)]], colWidths=[CONTENT_W])
    tbl.setStyle(TableStyle([
        ("BACKGROUND",    (0,0),(-1,-1), bg),
        ("LINEBEFORE",    (0,0),(0,-1),  4, line_color),
        ("BOX",           (0,0),(-1,-1), 0.5, GREY_BORDER),
        ("TOPPADDING",    (0,0),(-1,-1), 7),
        ("BOTTOMPADDING", (0,0),(-1,-1), 7),
        ("LEFTPADDING",   (0,0),(-1,-1), 12),
        ("RIGHTPADDING",  (0,0),(-1,-1), 10),
    ]))
    return tbl

def example_box(text):
    return info_box(text, bg=GREEN_LIGHT, line_color=GREEN, label="📖 Example")

def warn_box(text):
    return info_box(text, bg=ORANGE_LIGHT, line_color=ORANGE, label="⚠️ Key Point")

def code_box(lines):
    content = "<br/>".join(lines)
    tbl = Table([[Paragraph(content, CODE_S)]], colWidths=[CONTENT_W])
    tbl.setStyle(TableStyle([
        ("BACKGROUND",    (0,0),(-1,-1), colors.HexColor("#f3f4f6")),
        ("LINEBEFORE",    (0,0),(0,-1),  3.5, ACCENT),
        ("BOX",           (0,0),(-1,-1), 0.5, GREY_BORDER),
        ("TOPPADDING",    (0,0),(-1,-1), 8),
        ("BOTTOMPADDING", (0,0),(-1,-1), 8),
        ("LEFTPADDING",   (0,0),(-1,-1), 12),
    ]))
    return tbl

def comparison_table(headers, rows, col_widths=None):
    if col_widths is None:
        n = len(headers)
        col_widths = [CONTENT_W / n] * n
    data = [headers] + rows
    tbl = Table(data, colWidths=col_widths, repeatRows=1)
    row_bg = [WHITE, GREY_LIGHT]
    tbl.setStyle(TableStyle([
        ("BACKGROUND",     (0,0),(-1,0),  NAVY),
        ("TEXTCOLOR",      (0,0),(-1,0),  WHITE),
        ("FONTNAME",       (0,0),(-1,0),  "Helvetica-Bold"),
        ("FONTSIZE",       (0,0),(-1,0),  9),
        ("ALIGN",          (0,0),(-1,-1), "CENTER"),
        ("VALIGN",         (0,0),(-1,-1), "MIDDLE"),
        ("FONTNAME",       (0,1),(-1,-1), "Helvetica"),
        ("FONTSIZE",       (0,1),(-1,-1), 9),
        ("ROWBACKGROUNDS", (0,1),(-1,-1), row_bg),
        ("GRID",           (0,0),(-1,-1), 0.4, GREY_BORDER),
        ("TOPPADDING",     (0,0),(-1,-1), 5),
        ("BOTTOMPADDING",  (0,0),(-1,-1), 5),
        ("LEFTPADDING",    (0,0),(-1,-1), 6),
        ("RIGHTPADDING",   (0,0),(-1,-1), 6),
    ]))
    return tbl

def diagram_box(lines, caption=""):
    content = "<br/>".join(lines)
    st = S("diag", fontSize=8.5, textColor=DEEP_NAVY, fontName="Courier",
           leading=12, alignment=TA_CENTER)
    inner = [[Paragraph(content, st)]]
    if caption:
        inner.append([Paragraph(caption, CAPTION)])
    tbl = Table(inner, colWidths=[CONTENT_W])
    tbl.setStyle(TableStyle([
        ("BACKGROUND",    (0,0),(0,0),  colors.HexColor("#eceff1")),
        ("BOX",           (0,0),(-1,-1),1.2, MED_NAVY),
        ("TOPPADDING",    (0,0),(-1,-1),10),
        ("BOTTOMPADDING", (0,0),(-1,-1),6),
        ("LEFTPADDING",   (0,0),(-1,-1),10),
        ("ALIGN",         (0,0),(-1,-1),"CENTER"),
    ]))
    return tbl

def toc_entry(num, title, color=ACCENT):
    st_n = S("tn", fontSize=11, textColor=color, fontName="Helvetica-Bold", leading=14)
    st_t = S("tt", fontSize=11, textColor=GREY_DARK, fontName="Helvetica", leading=14)
    tbl = Table([[Paragraph(f"{num}.", st_n), Paragraph(title, st_t)]],
                colWidths=[14*mm, CONTENT_W - 14*mm])
    tbl.setStyle(TableStyle([
        ("TOPPADDING",    (0,0),(-1,-1), 3),
        ("BOTTOMPADDING", (0,0),(-1,-1), 3),
        ("VALIGN",        (0,0),(-1,-1), "MIDDLE"),
    ]))
    return tbl

# ══════════════════════════════════════════════════════════════════════════════
story = []

# ═══════════════════════════════ COVER PAGE ═══════════════════════════════════
cover = Table([
    [Paragraph("COMPUTER ORGANIZATION<br/>&amp; ARCHITECTURE", COVER_H1)],
    [sp(12)],
    [Paragraph("Multiprocessor Architecture", COVER_H2)],
    [Paragraph("Complete Detailed Study Notes", COVER_H2)],
    [sp(20)],
    [Paragraph(
        "Taxonomy of Parallel Architectures  •  Centralized Shared-Memory  •  "
        "Synchronization<br/>Memory Consistency  •  Interconnection Networks  •  "
        "Distributed Shared Memory<br/>Cluster Computers  •  Dataflow Computers  •  "
        "Reduction Architectures  •  Systolic Arrays",
        COVER_SUB)],
    [sp(30)],
    [Paragraph("B.Tech — Information Technology", COVER_SUB)],
    [Paragraph("Computer Organization &amp; Architecture", COVER_SUB)],
], colWidths=[CONTENT_W])
cover.setStyle(TableStyle([
    ("BACKGROUND", (0,0),(-1,-1), DEEP_NAVY),
    ("TOPPADDING", (0,0),(-1,-1), 8),
    ("BOTTOMPADDING",(0,0),(-1,-1),8),
    ("ALIGN",      (0,0),(-1,-1),"CENTER"),
]))
story.append(cover)
story.append(PageBreak())

# ═══════════════════════════ TABLE OF CONTENTS ════════════════════════════════
story.append(section_bar("Table of Contents", DEEP_NAVY))
story.append(sp(8))
toc = [
    ("1", "Introduction to Multiprocessor Systems"),
    ("2", "Flynn's Taxonomy — Classification of Parallel Architectures"),
    ("3", "Centralized Shared-Memory Architecture (SMP / UMA)"),
    ("4", "Cache Coherence in Shared-Memory Systems"),
    ("5", "Synchronization in Multiprocessor Systems"),
    ("6", "Memory Consistency Models"),
    ("7", "Interconnection Networks"),
    ("8", "Distributed Shared Memory (DSM) Architecture"),
    ("9", "Non-Uniform Memory Access (NUMA)"),
    ("10","Cluster Computers"),
    ("11","Non-Von Neumann Architectures — Overview"),
    ("12","Dataflow Computer Architecture"),
    ("13","Reduction Computer Architecture"),
    ("14","Systolic Array Architecture"),
    ("15","Comparison Summary & Quick Revision"),
]
for num, title in toc:
    story.append(toc_entry(num, title))
    story.append(divider(GREY_BORDER, 0.4))
story.append(PageBreak())

# ══════════════════════════════════════════════════════════════════════════════
# CHAPTER 1 — INTRODUCTION
# ══════════════════════════════════════════════════════════════════════════════
story.append(chapter_header("1", "Introduction to Multiprocessor Systems",
    "Why single processors are not enough"))
story.append(sp(8))

story.append(Paragraph(
    "For decades, computer architects focused on improving the performance of a single processor "
    "by increasing clock frequency, deepening pipelines, and adding more transistors. However, "
    "around the mid-2000s, this approach hit fundamental physical walls — power consumption grew "
    "exponentially, heat dissipation became unmanageable, and wire delays across the chip started "
    "limiting clock speeds. This phenomenon is often referred to as the <b>Power Wall</b>, the "
    "<b>Memory Wall</b> (memory latency not keeping up with processor speed), and the "
    "<b>Instruction-Level Parallelism Wall</b> (diminishing returns from ILP). The natural "
    "solution was to place multiple processing units (cores or processors) on the same chip or "
    "within the same system and let them cooperate — this is the foundation of "
    "<b>multiprocessor architecture</b>.", BODY))

story.append(sp(4))
story.append(section_bar("1.1  What is a Multiprocessor System?"))
story.append(sp(4))
story.append(Paragraph(
    "A multiprocessor system is a computer system that contains two or more processors (CPUs or "
    "cores) that share resources such as memory, I/O devices, and interconnect buses, and that "
    "cooperate to execute tasks simultaneously. The processors may work on different parts of the "
    "same problem (parallel computing) or on completely different tasks (multiprogramming). "
    "The key distinguishing characteristic of multiprocessors — as opposed to multicomputers — "
    "is that they share a single address space: all processors can read and write the same "
    "memory locations, which greatly simplifies communication between them.", BODY))

story.append(sp(4))
story.append(section_bar("1.2  Goals of Multiprocessor Design"))
story.append(sp(4))
story.append(Paragraph(
    "The primary goal of multiprocessor design is to achieve <b>scalable performance</b> — "
    "adding more processors should result in a proportional increase in throughput or reduction "
    "in execution time. Three key metrics guide multiprocessor design:", BODY))

goals_data = [
    ["Metric", "Description", "Challenge"],
    ["Throughput", "Total work done per unit time across all processors",
     "Keeping all processors busy (load balancing)"],
    ["Latency", "Time to complete a single task",
     "Communication overhead between processors"],
    ["Scalability", "Performance growth as processors are added",
     "Bottlenecks in memory, buses, or interconnect"],
]
story.append(comparison_table(goals_data[0], goals_data[1:], [45*mm, 72*mm, 66*mm]))
story.append(sp(4))
story.append(info_box(
    "Amdahl's Law limits parallel speedup: if fraction f of a program is parallelizable, "
    "maximum speedup = 1 / [(1-f) + f/N] where N is the number of processors. Even with "
    "infinite processors, a program with 20% sequential code can only achieve 5x speedup."))
story.append(PageBreak())

# ══════════════════════════════════════════════════════════════════════════════
# CHAPTER 2 — FLYNN'S TAXONOMY
# ══════════════════════════════════════════════════════════════════════════════
story.append(chapter_header("2", "Flynn's Taxonomy",
    "Classification of Parallel Computer Architectures"))
story.append(sp(8))

story.append(Paragraph(
    "In 1966, Michael J. Flynn proposed a classification scheme for computer architectures "
    "based on two independent dimensions: the number of <b>instruction streams</b> and the "
    "number of <b>data streams</b> that a machine can process simultaneously. A stream is a "
    "sequence of instructions or data items being operated upon. This taxonomy remains the "
    "most widely used framework for describing parallel architectures, even though modern "
    "systems sometimes blur these boundaries.", BODY))

story.append(sp(6))
story.append(diagram_box([
    "                    INSTRUCTION STREAMS",
    "                  Single          Multiple",
    "         ┌─────────────────┬──────────────────┐",
    "  D  Single│    SISD        │      MISD        │",
    "  A        │  (Von Neumann) │  (rarely exists) │",
    "  T        ├─────────────────┼──────────────────┤",
    "  A  Multiple│    SIMD        │      MIMD        │",
    "         │  (Vector/GPU)  │  (Multiprocessor)│",
    "  S      └─────────────────┴──────────────────┘",
    "  T",
    "  R",
    "  E",
    "  A",
    "  M",
    "  S",
], "Flynn's Taxonomy — 2×2 Classification Matrix"))

story.append(sp(6))
story.append(section_bar("2.1  SISD — Single Instruction, Single Data"))
story.append(sp(4))
story.append(Paragraph(
    "SISD is the classical von Neumann architecture in which a single processor executes a "
    "single stream of instructions, each operating on a single data element at a time. There "
    "is no parallelism at the architectural level, although pipelining can create an illusion "
    "of overlap. All traditional uniprocessors — from early mainframes to simple embedded "
    "microcontrollers — fall into this category. Examples include the Intel 8086, early MIPS "
    "processors, and any simple single-core CPU without vector extensions.", BODY))

story.append(sp(4))
story.append(section_bar("2.2  SIMD — Single Instruction, Multiple Data"))
story.append(sp(4))
story.append(Paragraph(
    "In SIMD architecture, a single control unit broadcasts the same instruction to multiple "
    "processing elements (PEs) simultaneously, but each PE operates on a different data element. "
    "This is extremely efficient for data-parallel problems such as image processing, signal "
    "processing, scientific simulations, and machine learning — any domain where the same "
    "operation must be applied to a large array of values.", BODY))
story.append(sp(3))
story.append(Paragraph(
    "The classic example of SIMD hardware is a <b>vector processor</b>, which has special "
    "registers that hold arrays of values (vectors) and instructions that operate on entire "
    "vectors in a single step. Modern CPUs include SIMD extension instruction sets such as "
    "<b>Intel SSE</b> (128-bit), <b>AVX</b> (256-bit), and <b>AVX-512</b> (512-bit), which "
    "allow 16 floating-point numbers to be added simultaneously with a single instruction. "
    "GPUs (Graphics Processing Units) are the most prominent SIMD-like architectures today, "
    "containing thousands of small cores that execute the same shader or CUDA kernel across "
    "millions of pixels or data elements in parallel.", BODY))
story.append(sp(3))
story.append(example_box(
    "Example: Adding two arrays A[1024] and B[1024]. In SISD, 1024 separate ADD instructions "
    "are needed. With 256-bit AVX SIMD (8 floats per register), only 128 vector-ADD instructions "
    "are needed — an 8x reduction in instruction count."))

story.append(sp(4))
story.append(section_bar("2.3  MISD — Multiple Instruction, Single Data"))
story.append(sp(4))
story.append(Paragraph(
    "MISD is a theoretical category where multiple processors execute different instructions on "
    "the same data simultaneously. In practice, very few real machines fit this description. "
    "Some fault-tolerant systems, where the same data is processed by multiple independent units "
    "and results are compared for voting (like the Space Shuttle flight computer), are sometimes "
    "cited as approximate MISD examples. Systolic arrays are also sometimes placed here. "
    "MISD has no widely commercially used implementation.", BODY))

story.append(sp(4))
story.append(section_bar("2.4  MIMD — Multiple Instruction, Multiple Data"))
story.append(sp(4))
story.append(Paragraph(
    "MIMD is the most general and most prevalent parallel architecture. Multiple processors "
    "each execute their own independent instruction streams on their own independent data "
    "streams. Processors may cooperate on a single problem or run completely independent tasks. "
    "The vast majority of modern parallel systems — from dual-core laptops to supercomputers "
    "with thousands of nodes — are MIMD systems. MIMD divides further into two critical "
    "subcategories based on memory organization:", BODY))
story.append(sp(4))

mimd_data = [
    ["Subcategory", "Memory Model", "Communication", "Example"],
    ["Shared Memory\n(Multiprocessor)", "All processors share a single physical address space",
     "Read/write shared variables", "SMP servers, multi-core CPUs"],
    ["Distributed Memory\n(Multicomputer)", "Each processor has its own private memory",
     "Explicit message passing (MPI)", "Clusters, Beowulf systems, supercomputers"],
]
story.append(comparison_table(mimd_data[0], mimd_data[1:], [40*mm, 55*mm, 50*mm, 38*mm]))
story.append(sp(4))
story.append(warn_box(
    "The distinction between shared-memory and distributed-memory MIMD is the most "
    "important division in multiprocessor architecture. Everything that follows in "
    "this course revolves around this distinction."))
story.append(PageBreak())

# ══════════════════════════════════════════════════════════════════════════════
# CHAPTER 3 — CENTRALIZED SHARED MEMORY (SMP/UMA)
# ══════════════════════════════════════════════════════════════════════════════
story.append(chapter_header("3", "Centralized Shared-Memory Architecture",
    "Symmetric Multiprocessing (SMP) / Uniform Memory Access (UMA)"))
story.append(sp(8))

story.append(Paragraph(
    "Centralized shared-memory architecture is the most straightforward multiprocessor "
    "design. In this model, all processors connect to a single, centralized main memory "
    "through a common interconnect — typically a shared bus. Because every processor has "
    "equal access time to any memory location, this architecture is also called "
    "<b>Uniform Memory Access (UMA)</b>. When all processors run the same operating system "
    "and have symmetric roles, it is called <b>Symmetric Multiprocessing (SMP)</b>. "
    "Most commercial servers from the 1990s through 2000s, and every modern multi-core "
    "processor chip, are fundamentally UMA/SMP architectures.", BODY))

story.append(sp(6))
story.append(diagram_box([
    "  ┌──────┐  ┌──────┐  ┌──────┐  ┌──────┐",
    "  │ CPU0 │  │ CPU1 │  │ CPU2 │  │ CPU3 │",
    "  │[Cache]│  │[Cache]│  │[Cache]│  │[Cache]│",
    "  └──┬───┘  └──┬───┘  └──┬───┘  └──┬───┘",
    "     │         │         │         │",
    "  ═══╪═════════╪═════════╪═════════╪═══  Shared Bus",
    "     │         │         │         │",
    "  ┌──┴─────────┴─────────┴─────────┴───┐",
    "  │          Main Memory (RAM)          │",
    "  └─────────────────────────────────────┘",
], "Centralized Shared-Memory (SMP/UMA) Architecture"))

story.append(sp(6))
story.append(section_bar("3.1  Characteristics of Centralized Shared Memory"))
story.append(sp(4))
story.append(Paragraph(
    "In a centralized shared-memory system, the single physical memory is addressed by a "
    "single global address space. Any processor can load or store any memory location using "
    "ordinary load/store instructions — no special communication primitives are needed. "
    "This dramatically simplifies programming compared to distributed-memory systems. "
    "The operating system can freely schedule any thread on any processor because all "
    "processors see the same data.", BODY))
story.append(sp(3))
story.append(Paragraph(
    "Each processor typically has its own private <b>cache</b> to reduce the number of times "
    "it must access the shared memory over the bus. Without caches, the shared bus would become "
    "a severe bottleneck — even 4 processors simultaneously trying to access memory would "
    "overload a single bus. With caches, the vast majority (95%+) of memory accesses are "
    "satisfied locally, dramatically reducing bus traffic. However, caches introduce a new "
    "critical problem: <b>cache coherence</b>.", BODY))

story.append(sp(4))
story.append(section_bar("3.2  The Scalability Problem"))
story.append(sp(4))
story.append(Paragraph(
    "The fundamental limitation of centralized shared-memory architecture is scalability. "
    "The shared bus has a fixed bandwidth. As more processors are added, contention for "
    "the bus increases. Each processor that misses in its cache must use the bus to fetch "
    "data from memory, competing with all other processors doing the same. Empirically, "
    "shared-bus SMP systems scale well up to about <b>8 to 16 processors</b>. Beyond that, "
    "the bus becomes a bottleneck and performance actually degrades. This is why large-scale "
    "multiprocessors use more sophisticated interconnects and memory organizations (NUMA, "
    "message-passing clusters).", BODY))
story.append(sp(4))
story.append(info_box(
    "The shared bus has a bandwidth of, say, 1 GB/s. If each of 8 processors generates "
    "a cache miss every 10 ns, each needing 64 bytes, bus demand = 8 × (64B / 10ns) = "
    "51.2 GB/s — 51x the bus capacity. This is why bus-based SMP does not scale beyond ~16 processors."))
story.append(PageBreak())

# ══════════════════════════════════════════════════════════════════════════════
# CHAPTER 4 — CACHE COHERENCE
# ══════════════════════════════════════════════════════════════════════════════
story.append(chapter_header("4", "Cache Coherence in Shared-Memory Systems",
    "The Problem of Multiple Caches with Shared Data"))
story.append(sp(8))

story.append(Paragraph(
    "When multiple processors each have their own private cache and share a common memory, "
    "a critical consistency problem arises: if two processors both cache the same memory "
    "location and one of them writes a new value, the other processor's cached copy becomes "
    "<b>stale</b> — it holds an old, incorrect value. If the second processor then reads its "
    "stale copy, it gets wrong data, leading to incorrect program execution. This is the "
    "<b>cache coherence problem</b>, and solving it is one of the central challenges of "
    "shared-memory multiprocessor design.", BODY))

story.append(sp(4))
story.append(example_box(
    "Scenario: Memory[X] = 10. CPU0 reads X → Cache0[X]=10. CPU1 reads X → Cache1[X]=10. "
    "CPU0 writes X=99 → Cache0[X]=99 but Memory[X] may still be 10 and Cache1[X] is still 10. "
    "CPU1 now reads X from its cache and gets 10 — a stale, WRONG value. This is a coherence violation."))

story.append(sp(4))
story.append(section_bar("4.1  Definition of Cache Coherence"))
story.append(sp(4))
story.append(Paragraph(
    "A memory system is cache coherent if and only if: (1) A read by processor P of a "
    "location X that follows a write to X by P, with no other processor writing X between "
    "those operations, always returns the value written by P. (2) A read by processor P of "
    "location X that follows a write to X by another processor Q returns the written value "
    "if the read and write are separated sufficiently in time. (3) Writes to the same "
    "location are serialized — two writes to the same location by any two processors are "
    "seen in the same order by all processors.", BODY))

story.append(sp(4))
story.append(section_bar("4.2  Snooping Cache Coherence Protocols"))
story.append(sp(4))
story.append(Paragraph(
    "On a shared bus, every bus transaction is visible to all processors — they can "
    "'snoop' on each other's bus traffic. Snooping protocols use this property to maintain "
    "coherence without a central directory. Every cache controller monitors the bus and "
    "takes action when it sees a relevant address. There are two main snooping strategies:", BODY))
story.append(sp(4))

story.append(sub_bar("4.2.1  Write-Invalidate Protocol (Most Common)"))
