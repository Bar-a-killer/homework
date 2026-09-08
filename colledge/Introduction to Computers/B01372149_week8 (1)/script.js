const input = document.getElementById('search-input');
const addBtn = document.getElementById('add-btn');
const resetBtn = document.getElementById('reset-btn');
const list = document.getElementById('item-list');

// 項目資料存在陣列中
let items = [];

function renderList() {
    // 每次渲染前先清空 ul
    list.innerHTML = '';

    items.forEach((item, idx) => {
    const li = document.createElement('li');

    const span = document.createElement('span');
    span.textContent = item;
    li.appendChild(span);

    // 編輯按鈕
    const editBtn = document.createElement('button');
    editBtn.textContent = '編輯';
    editBtn.onclick = () => {
        const editInput = document.createElement('input');
        editInput.type = 'text';
        editInput.value = item;
        editInput.className = 'edit-input';

        li.replaceChild(editInput, span);
        editBtn.textContent = '儲存';
        editBtn.onclick = () => {
        items[idx] = editInput.value;
        renderList();
        };
    };
    li.appendChild(editBtn);

    // 刪除按鈕
    const deleteBtn = document.createElement('button');
    deleteBtn.textContent = '刪除';
    deleteBtn.onclick = () => {
        items.splice(idx, 1);
        renderList();
    };
    li.appendChild(deleteBtn);

    list.appendChild(li);
    });
}

addBtn.onclick = () => {
    const value = input.value.trim();
    if (value !== '') {
    items.push(value);
    input.value = '';
    renderList();
    }
};

resetBtn.onclick = () => {
    input.value = '';
    items = [];
    renderList();
};

document.getElementById("nighnigh").addEventListener("click", function () {
    for (let i = 1; i <= 9; i++) {

        // 奇數：1 → 9
        if (i % 2 === 1) {
            for (let j = 1; j <= 9; j++) {
                console.log(`${i} x ${j} = ${i * j} `);
            }
        } 
        
        // 偶數：9 → 1
        else {
            for (let j = 9; j >= 1; j--) {
                console.log(`${i} x ${j} = ${i * j} `);
            }
        }

        console.log("");  // 換行
    }
});
const btn = document.getElementById("kalakala");

btn.addEventListener("click", function () {
    window.open("/kalakala");
});
const btn2 = document.getElementById("puzzle");

btn2.addEventListener("click", function () {
    window.open("/puzzle");
});
// 初始渲染
renderList();