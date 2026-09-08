from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import ParagraphStyle
from reportlab.lib.units import cm
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Table, TableStyle, PageBreak, HRFlowable
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib import colors
from reportlab.lib.enums import TA_CENTER, TA_LEFT, TA_JUSTIFY

# 註冊中文字體
pdfmetrics.registerFont(TTFont('NotoSans', '/tmp/NotoSansTC.ttf'))
pdfmetrics.registerFont(TTFont('NotoSansBold', '/tmp/NotoSansTC.ttf'))

# 頁面設定
doc = SimpleDocTemplate(
    './刑法概要學期報告_江其恩.pdf',
    pagesize=A4,
    rightMargin=2.5*cm,
    leftMargin=2.5*cm,
    topMargin=2.5*cm,
    bottomMargin=2.5*cm
)

W, H = A4

# 樣式定義
def style(name, font='NotoSans', size=12, leading=None, alignment=TA_LEFT,
          spaceBefore=0, spaceAfter=6, leftIndent=0, textColor=colors.black, bold=False):
    if leading is None:
        leading = size * 1.8
    f = 'NotoSansBold' if bold else font
    return ParagraphStyle(
        name,
        fontName=f,
        fontSize=size,
        leading=leading,
        alignment=alignment,
        spaceBefore=spaceBefore,
        spaceAfter=spaceAfter,
        leftIndent=leftIndent,
        textColor=textColor,
        wordWrap='CJK'
    )

s_title     = style('title',     size=20, alignment=TA_CENTER, spaceBefore=30, spaceAfter=10, bold=True)
s_subtitle  = style('subtitle',  size=13, alignment=TA_CENTER, spaceBefore=6,  spaceAfter=6)
s_cover_lbl = style('cover_lbl', size=13, alignment=TA_CENTER, spaceBefore=10, spaceAfter=4)
s_h1        = style('h1',        size=14, spaceBefore=18, spaceAfter=6, bold=True)
s_h2        = style('h2',        size=12, spaceBefore=12, spaceAfter=4, bold=True)
s_h3        = style('h3',        size=11, spaceBefore=8,  spaceAfter=3, bold=True)
s_body      = style('body',      size=11, spaceBefore=2,  spaceAfter=4, alignment=TA_JUSTIFY)
s_body_ind  = style('body_ind',  size=11, spaceBefore=2,  spaceAfter=4, alignment=TA_JUSTIFY, leftIndent=20)
s_quote     = style('quote',     size=10.5, spaceBefore=4, spaceAfter=4, alignment=TA_JUSTIFY,
                    leftIndent=30, textColor=colors.HexColor('#333333'))
s_toc       = style('toc',       size=11, spaceBefore=4,  spaceAfter=4)
s_center    = style('center',    size=11, alignment=TA_CENTER, spaceBefore=4, spaceAfter=4)

# 表格內專用樣式（置中與白色文字）
s_tbl_header = style('tbl_header', size=10, alignment=TA_CENTER, textColor=colors.white, bold=True, spaceAfter=0)
s_tbl_body   = style('tbl_body',   size=10, alignment=TA_CENTER, spaceAfter=0)

story = []

# ── 封面 ──────────────────────────────────────────────
story.append(Spacer(1, 3*cm))
story.append(Paragraph('刑法概要學期報告', s_title)) 
story.append(HRFlowable(width='80%', thickness=1.5, color=colors.HexColor('#444444'), spaceAfter=20))
story.append(Spacer(1, 1.2*cm))

cover_data = [
    ['課程名稱', '刑法概要'], 
    ['指導老師', '周成瑜 博士'], 
    ['報告主題', '乘機性交罪既、未遂之認定'], 
    ['報告案號', '臺灣新北地院 105 年度侵訴字第 31 號判決（未遂）'], 
    ['',         '臺灣高等法院 106 年度侵上訴字第 84 號判決（未遂）'], 
    ['',         '最高法院 107 年度台上字第 678 號判決（駁回）'], 
    ['系級姓名', '資工2A  江其恩  01372149'], 
]

ct = Table(cover_data, colWidths=[3.5*cm, 11*cm])
ct.setStyle(TableStyle([
    ('FONTNAME',    (0,0), (-1,-1), 'NotoSans'),
    ('FONTNAME',    (0,0), (0,-1),  'NotoSansBold'),
    ('FONTSIZE',    (0,0), (-1,-1), 11.5),
    ('LEADING',     (0,0), (-1,-1), 22),
    ('VALIGN',      (0,0), (-1,-1), 'MIDDLE'),
    ('TOPPADDING',  (0,0), (-1,-1), 7),
    ('BOTTOMPADDING',(0,0),(-1,-1), 7),
    ('LEFTPADDING', (0,0), (-1,-1), 8),
    ('RIGHTPADDING',(0,0), (-1,-1), 8),
    ('ROWBACKGROUNDS',(0,0),(-1,-1),[colors.HexColor('#F5F5F5'), colors.white]),
    ('BOX',          (0,0), (-1,-1), 0.5, colors.HexColor('#AAAAAA')),
    ('INNERGRID',   (0,0), (-1,-1), 0.3, colors.HexColor('#CCCCCC')),
    ('SPAN',        (0,3), (0,5)),  # 案號跨列
]))
story.append(ct)
story.append(PageBreak())

# ── 報告大綱 ──────────────────────────────────────────
story.append(Paragraph('報告大綱', s_h1)) 
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=8))
toc_items = [
    '一、罪章條文說明', 
    '二、事實經過', 
    '三、爭議點', 
    '四、各該案號判決理由分析', 
    '五、心得（是否認同判決、如何預防避免）', 
]
for item in toc_items:
    story.append(Paragraph(item, s_toc))
story.append(PageBreak())

# ── 一、罪章條文說明 ─────────────────────────────────
story.append(Paragraph('一、罪章條文說明', s_h1)) 
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=6))

story.append(Paragraph('（一）乘機性交罪之法條依據', s_h2)) 
story.append(Paragraph(
    '本案所涉主要法條為中華民國刑法第225條（乘機性交猥褻罪），條文內容如下：', s_body)) 

quote_data = [
    [
        Paragraph('第一項', s_tbl_body),
        Paragraph(
            '對於男女，利用其精神、身體障礙、心智缺陷或其他相類之情形，'
            '不能或不知抗拒而為性交者，處三年以上十年以下有期徒刑。',
            s_body
        )
    ],
    [
        Paragraph('第二項', s_tbl_body),
        Paragraph(
            '對於男女，利用其精神、身體障礙、心智缺陷或其他相類之情形，'
            '不能或不知抗拒而為猥褻之行為者，處六月以上五年以下有期徒刑。',
            s_body
        )
    ],
    [
        Paragraph('第三項', s_tbl_body),
        Paragraph('第一項之未遂犯罰之。', s_body)
    ]
]
qt = Table(quote_data, colWidths=[2*cm, 12.5*cm])
qt.setStyle(TableStyle([
    ('FONTNAME',     (0,0), (-1,-1), 'NotoSans'),
    ('FONTNAME',     (0,0), (0,-1),  'NotoSansBold'),
    ('FONTSIZE',     (0,0), (-1,-1), 10.5),
    ('LEADING',      (0,0), (-1,-1), 20),
    ('VALIGN',       (0,0), (-1,-1), 'TOP'),
    ('TOPPADDING',   (0,0), (-1,-1), 6),
    ('BOTTOMPADDING',(0,0), (-1,-1), 6),
    ('LEFTPADDING',  (0,0), (-1,-1), 8),
    ('BACKGROUND',   (0,0), (-1,-1), colors.HexColor('#F9F9F9')),
    ('BOX',          (0,0), (-1,-1), 0.5, colors.HexColor('#AAAAAA')),
    ('INNERGRID',    (0,0), (-1,-1), 0.3, colors.HexColor('#DDDDDD')),
]))
story.append(qt)
story.append(Spacer(1, 8))

story.append(Paragraph('（二）「性交」之定義', s_h2)) 
story.append(Paragraph(
    '依刑法第10條第5項規定，所謂「性交」，係指非基於正當目的所為之下列性侵入行為：', s_body)) 
story.append(Paragraph('1. 以性器進入他人之性器、肛門或口腔，或使之接合之行為。', s_body_ind)) 
story.append(Paragraph('2. 以性器以外之其他身體部位或器物進入他人之性器、肛門，或使之接合之行為。', s_body_ind)) 

story.append(Paragraph('（三）本罪之構成要件分析', s_h2)) 
story.append(Paragraph('【客觀構成要件】', s_h3)) 
story.append(Paragraph(
    '1. 行為主體：任何人均可構成本罪，男女皆可為行為人，男女皆可為被害人，性別中立。', s_body)) 
story.append(Paragraph(
    '2. 被害人之狀態：被害人須因精神障礙、身體障礙、心智缺陷或其他相類情形（如酒醉昏睡、藥物影響），而處於「不能或不知抗拒」之狀態。所謂「相類情形」，依最高法院見解，係指被害人雖非精神、身體或心智障礙，但受性交時因昏暈、酣眠、泥醉等相類似情形，致無同意性交之理解，或無抗拒性交之能力者而言（最高法院96年度台上字第4376號判決意旨）。', s_body)) 
story.append(Paragraph(
    '3. 行為人之行為：行為人須「利用」上述不能或不知抗拒之狀態而為性交行為。此「利用」係指行為人並非自行製造被害人之無助狀態，而係乘機加以利用，此點為與強制性交罪之區別關鍵所在。', s_body)) 

story.append(Paragraph('【主觀構成要件】', s_h3)) 
story.append(Paragraph(
    '行為人須具有乘機性交之故意，即明知被害人處於不能或不知抗拒之狀態，仍有意加以利用而實行性交行為。', s_body)) 

story.append(Paragraph('【既遂與未遂之區分】', s_h3)) 
story.append(Paragraph(
    '依刑法第10條第5項及實務採行之「接合說」，性交既遂之認定，僅須性器或性器以外之其他身體部位進入他人性器，或使之接合，即屬既遂，並非以插入陰道為必要。最高法院111年度台上字第527號判決進一步闡明，女性外陰部生殖器官包括陰阜、大陰唇、小陰唇、陰蒂、前庭、陰道口、處女膜外側，凡以性器或性器以外之其他身體部位或器物進入大陰唇內側之性器之性侵入行為，均屬刑法第10條第5項所指之性交，並非以插入陰道深部為必要。', s_body)) 
story.append(Paragraph(
    '若行為人已著手實行性交行為，但因外力介入或其他原因而未達到上述「接合」程度，則成立未遂犯，依刑法第25條第2項規定，得按既遂犯之刑度減輕其刑。', s_body)) 

story.append(Paragraph('（四）本罪與強制性交罪之比較', s_h2)) 
story.append(Paragraph(
    '本罪（刑法第225條）與強制性交罪（刑法第221條）之最大差異，在於被害人陷入不能或不知抗拒之狀態的原因：', s_body)) 

# 修正：將表格內部文字封裝進 Paragraph 並改用 <br/> 換行，確保 ReportLab 能正確排版
compare_data = [
    [Paragraph('比較項目', s_tbl_header), Paragraph('乘機性交罪（第225條）', s_tbl_header), Paragraph('強制性交罪（第221條）', s_tbl_header)],
    [Paragraph('不能抗拒狀態之來源', s_tbl_body), Paragraph('被害人本身既有狀態<br/>（酒醉、障礙等）', s_tbl_body), Paragraph('行為人以強暴、脅迫<br/>等手段製造', s_tbl_body)],
    [Paragraph('行為人之手段', s_tbl_body), Paragraph('僅利用既有狀態', s_tbl_body), Paragraph('主動施以強制手段', s_tbl_body)], 
    [Paragraph('法定刑', s_tbl_body), Paragraph('3年以上、10年以下<br/>有期徒刑', s_tbl_body), Paragraph('3年以上、10年以下<br/>有期徒刑', s_tbl_body)]
]
cmp_t = Table(compare_data, colWidths=[4*cm, 5*cm, 5*cm])
cmp_t.setStyle(TableStyle([
    ('VALIGN',        (0,0), (-1,-1), 'MIDDLE'),
    ('TOPPADDING',   (0,0), (-1,-1), 8),
    ('BOTTOMPADDING',(0,0), (-1,-1), 8),
    ('BACKGROUND',   (0,0), (-1,0),  colors.HexColor('#3A3A3A')),
    ('ROWBACKGROUNDS',(0,1),(-1,-1),[colors.HexColor('#F0F0F0'), colors.white]),
    ('BOX',          (0,0), (-1,-1), 0.5, colors.HexColor('#888888')),
    ('INNERGRID',    (0,0), (-1,-1), 0.3, colors.HexColor('#BBBBBB')),
]))
story.append(cmp_t)
story.append(PageBreak())

# ── 二、事實經過 ─────────────────────────────────────
story.append(Paragraph('二、事實經過', s_h1)) 
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=6))

story.append(Paragraph('被告：王凱民', s_body)) 
story.append(Paragraph('被害人：A女（依性侵害犯罪防治法第12條規定，姓名依法遮蔽）', s_body)) 
story.append(Spacer(1, 6))
story.append(Paragraph(
    '民國104年6月27日晚間，被告王凱民與A女等一群人在某大學校區內聚會飲酒。至同年月28日凌晨3時許，A女已因大量飲酒而意識不清、全身癱軟無力，終至昏睡，處於類似精神障礙、不能及不知抗拒之狀態。', s_body)) 
story.append(Paragraph(
    '王凱民見A女酒醉昏睡，起乘機性交之犯意，利用A女不能及不知抗拒之機會，對A女著手實行性交行為。然而，就在王凱民實行性交行為之際，被A女的男友B男等人發現並即時阻止，導致性交行為未能完成（未遂）。', s_body)) 
story.append(Paragraph(
    '事後，A女被送往亞東醫院救治。警方採集A女外陰部棉棒送驗，鑑定結果在A女外陰部棉棒檢出一男性Y染色體DNA-STR型別，與王凱民之Y染色體DNA-STR型別相符。然而，在A女陰道深部及外陰部以酸性磷酸酵素法檢測，結果均呈弱陽性反應，以顯微鏡及前列腺抗原檢測法確認，並未發現精子細胞或精液反應，A女性器內亦未檢出任何王凱民之DNA。', s_body)) 
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=6))


# ── 三、爭議點 ───────────────────────────────────────
story.append(Paragraph('三、爭議點', s_h1)) 
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=6))

story.append(Paragraph('爭議一：乘機性交罪既遂或未遂之認定標準為何？', s_h2)) 

story.append(Paragraph('爭議二：A女是否確實處於「不能或不知抗拒」之狀態？', s_h2)) 

story.append(PageBreak())

# ── 四、各該案號判決理由分析 ─────────────────────────
story.append(Paragraph('四、各該案號判決理由分析', s_h1))
story.append(HRFlowable(width='100%', thickness=0.5,
                        color=colors.HexColor('#AAAAAA'),
                        spaceAfter=6))

# 一審
story.append(Paragraph(
    '（一）第一審：臺灣新北地方法院105年度侵訴字第31號判決',
    s_h2))

story.append(Paragraph(
    '判決結果：被告王凱民犯乘機性交未遂罪，處有期徒刑3年6月。',
    s_body))

story.append(Paragraph('1. 被害人已達不能或不知抗拒狀態', s_h3))

story.append(Paragraph(
    '法院綜合A女、A女男友及在場同學之證詞、消防局救護紀錄、'
    '亞東醫院診療資料等證據，認定A女於案發時因大量飲酒而意識不清、'
    '全身癱軟無力，最終昏睡失去反抗能力。法院認為此種酒醉昏睡情形，'
    '屬刑法第225條所稱「其他相類之情形」，已達不能及不知抗拒之程度。',
    s_body))

story.append(Paragraph('2. 醫學鑑定報告分析', s_h3))

story.append(Paragraph(
    '刑事警察局DNA鑑定結果顯示，A女外陰部棉棒檢體檢出男性'
    'Y染色體DNA-STR型別，與被告王凱民之型別相符。'
    '然而A女陰道深部檢體並未檢出王凱民DNA。'
    '另以酸性磷酸酵素法檢測雖呈弱陽性反應，'
    '但進一步以顯微鏡檢驗及前列腺抗原檢測法確認後，'
    '均未發現精子細胞或精液反應。',
    s_body))

story.append(Paragraph('3. 乘機性交犯意之認定', s_h3))

story.append(Paragraph(
    '法院認為，被告將A女攙扶至走廊隱密處後，'
    '脫去A女牛仔短褲及內褲，並脫下自己內外褲，'
    '再以身體碰觸A女外陰部，已足認被告主觀上具有'
    '乘機性交之犯意，並已著手實行性交行為。',
    s_body))

story.append(Paragraph('4. 既遂與未遂之法理判斷', s_h3))

story.append(Paragraph(
    '本案核心爭點在於性交行為究屬既遂或未遂。'
    '刑法實務向來採取接合說，認為性器與被害人性器'
    '發生法律上之接合即屬既遂，不以射精為必要。'
    '然而本案鑑定結果僅證明外陰部有被告DNA，'
    '無法證明陰莖已進入A女性器或發生接合。'
    '法院認為依罪疑唯輕原則，不得逕行推論既遂，'
    '故認定成立乘機性交未遂罪。',
    s_body))

# 二審
story.append(Paragraph(
    '（二）第二審：臺灣高等法院106年度侵上訴字第84號判決',
    s_h2))

story.append(Paragraph(
    '判決結果：駁回被告及檢察官上訴，維持第一審乘機性交未遂罪判決。',
    s_body))

story.append(Paragraph('1. 檢察官主張', s_h3))

story.append(Paragraph(
    '檢察官主張被告犯罪行為已達性交既遂程度，'
    '且另涉乘機猥褻犯行，認第一審認定過輕。',
    s_body))

story.append(Paragraph('2. 高等法院見解', s_h3))

story.append(Paragraph(
    '高等法院審酌全部證據後認為，雖可確認被告具有'
    '乘機性交犯意並已著手實行犯罪，但DNA及醫學鑑定結果'
    '仍無法證明陰莖已進入A女性器。'
    '由於既遂事實尚存合理懷疑，因此不能以推測補足證據不足。',
    s_body))

story.append(Paragraph('3. 證據裁判原則之適用', s_h3))

story.append(Paragraph(
    '高等法院強調刑事訴訟法採證據裁判主義，'
    '犯罪事實須以證據證明。'
    '在欠缺足夠客觀證據證明性交接合已發生之情況下，'
    '應維持未遂之認定。',
    s_body))

# 三審
story.append(Paragraph(
    '（三）第三審：最高法院107年度台上字第678號判決',
    s_h2))

story.append(Paragraph(
    '判決結果：以上訴不合法律上程式為由，駁回上訴，全案確定。',
    s_body))

story.append(Paragraph('判決理由分析', s_h3))

story.append(Paragraph(
    '最高法院指出，第三審屬法律審，其審查重點在於原判決是否違背法令，'
    '而非重新認定事實。原審已綜合卷內證據資料，認定被告利用A女酒醉昏睡、'
    '不能及不知抗拒之狀態而著手實行性交行為，其事實認定與證據取捨均無違反'
    '經驗法則及論理法則，因此無從撤銷原判決。',
    s_body))

story.append(Paragraph(
    '一、關於「不能或不知抗拒」之認定',
    s_h3))

story.append(Paragraph(
    '最高法院肯認原審見解，認為A女因大量飲酒而意識不清、全身癱軟無力，'
    '並陷入昏睡狀態，已屬刑法第225條所稱「其他相類之情形」，足認其處於'
    '不能及不知抗拒之狀態。此部分並有目擊證人證詞、救護紀錄表及醫療紀錄'
    '相互印證。',
    s_body))

story.append(Paragraph(
    '二、關於DNA鑑定證據之評價',
    s_h3))

story.append(Paragraph(
    '被告主張外陰部採得之Y染色體DNA-STR型別僅有11個基因位型別相符，'
    '不足證明檢體來自被告。惟最高法院引用刑事警察局函覆內容指出，'
    '其餘6個基因位型別雖因DNA量過少而無法判讀，但並未出現與被告型別'
    '相矛盾之結果，因此仍不排除該檢體來自被告本人或與其具同父系血緣關係之人。',
    s_body))

story.append(Paragraph(
    '法院進一步認為，被告當時已脫下自己及A女之褲子，並以身體壓在A女身上，'
    '因此外陰部所採得之DNA極可能係被告身體直接接觸A女外陰部所造成之轉移，'
    '足以作為認定被告已著手實行性交行為之重要證據。',
    s_body))

story.append(Paragraph(
    '三、關於既遂與未遂之區分',
    s_h3))

story.append(Paragraph(
    '本案最重要之爭點在於性交行為究竟已達既遂或僅屬未遂。法院指出，'
    '雖然A女外陰部檢出與被告相符之DNA，但A女陰道深部未檢出被告DNA，'
    '且酸性磷酸酵素檢驗雖呈弱陽性反應，惟顯微鏡檢驗及前列腺抗原檢測均'
    '未發現精子細胞或精液反應。',
    s_body))

story.append(Paragraph(
    '因此，現有證據僅能證明被告已接觸A女外陰部並著手實行性交行為，'
    '尚不足以證明陰莖已進入A女性器而完成法律上之性交接合。'
    '依罪疑唯輕原則，應作有利於被告之認定，因此成立乘機性交未遂罪。',
    s_body))

story.append(Paragraph(
    '四、本案確立之法律原則',
    s_h3))

story.append(Paragraph(
    '本案可歸納出三項重要法理：'
    '第一，酒醉昏睡達失去反抗能力之程度者，屬刑法第225條所稱不能或不知抗拒；'
    '第二，DNA鑑定結果得作為認定被告已著手實行性交行為之重要佐證；'
    '第三，性交既遂仍須有充分客觀證據證明性器接合事實，若證據不足以證明接合，'
    '即應依罪疑唯輕原則認定為未遂。',
    s_body))


# ── 五、心得 ─────────────────────────────────────────
story.append(Paragraph('五、心得', s_h1)) 
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=6))

story.append(Paragraph('（一）對本系列判決之評析', s_h2)) 
story.append(Paragraph(
    '本系列三個判決，自一審地院、二審高院至三審最高法院，均一致認定本案王凱民成立乘機性交未遂罪，整體而言，筆者認同此結論，理由如下：', s_body)) 

story.append(Paragraph('1. 被害人不能抗拒狀態之認定合理', s_h3)) 
story.append(Paragraph(
    '本案中，A女酒醉昏睡、全身癱軟之事實，有多名在場目擊者之一致證詞，及消防救護紀錄、醫院文件等客觀書證相互印證，足以排除合理懷疑，確認A女當時已處於不能及不知抗拒之狀態，符合刑法第225條第1項所定「相類情形」之要件。', s_body)) 

story.append(Paragraph('2. 未遂認定之謹慎態度值得肯定', s_h3)) 
story.append(Paragraph(
    '就既遂與未遂之認定，法院在欠缺精液、精子細胞之明確鑑定依據的情況下，並未輕率認定既遂，而是依「罪疑唯輕」之刑事訴訟基本原則，以「尚難遽認」之措辭，審慎認定未遂，展現司法應有的謹慎態度，保障了被告不受過度入罪的基本權利。', s_body)) 

story.append(Paragraph('3. 性交定義之實務操作有待釐清', s_h3)) 
story.append(Paragraph(
    '本案發生時（民國104年）及三審判決作成時（民國107年），實務上對於性交既遂之「接合說」雖已確立，但對於「進入大陰唇內側即屬既遂」之見解，係在後來（最高法院111年度台上字第527號判決）方更明確地加以闡釋。本案判決作成時，DNA僅採得於外陰部，且無法確認係精子細胞，法院選擇不認定既遂，在當時的法律解釋框架下是合理謹慎的。', s_body)) 

story.append(Paragraph('（二）如何預防、避免類似事件的發生', s_h2)) 
story.append(Paragraph(
    '本案呈現的是利用他人酒醉昏睡、乘機性侵的犯罪型態，對個人性自主權及身體安全造成嚴重侵害。預防此類事件，可從以下幾個層面著手：', s_body)) 

story.append(Paragraph('【個人層面】', s_h3)) 
story.append(Paragraph(
    '1. 飲酒時應掌握自身酒量，避免飲酒過量以致失去自我保護能力，聚會時應與可信任的朋友相互照應。', s_body)) 
story.append(Paragraph('2. 不單獨與不熟識的人留在封閉空間，並注意周遭環境的安全。', s_body)) 
story.append(Paragraph(
    '3. 提升法律意識，認識到「對方沒有明確表示同意」並非自動授予同意，且酒醉失去意識者在法律上完全不具備同意性交之能力。', s_body)) 

story.append(Paragraph('【社會層面】', s_h3)) 
story.append(Paragraph(
    '1. 強化性別平等教育，糾正「對方喝酒就是默許」等錯誤觀念，建立尊重他人性自主意願的文化。', s_body)) 
story.append(Paragraph('2. 鼓勵旁觀者介入（如本案之B男及時阻止），建立守望相助的社群意識。', s_body)) 

story.append(Spacer(1, 1*cm))
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=8))

doc.build(story)
print('PDF生成完成')