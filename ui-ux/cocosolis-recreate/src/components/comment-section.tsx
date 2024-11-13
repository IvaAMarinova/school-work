import Comment from './comment';

function CommentsSection() {
    const commentsData = [
        {
            user: { initials: "ДД", name: "Даниела Д." },
            date: "08.07.2024",
            rating: 5,
            content: "Копринено нежни масла за кожата. Ароматите са превъзходни.",
            imageSrc: "https://cdn-yotpo-images-production.yotpo.com/Review/597262794/583487344/square.jpg?1720422219",
            productLink: "#",
        },
        {
            user: { initials: "КВ", name: "Калина В." },
            date: "23.06.2024",
            rating: 5,
            content: "Уникално масло! Уникален аромат!",
            imageSrc: "https://cdn-yotpo-images-production.yotpo.com/Review/592707184/577725141/square.jpg?1719135477",
            productLink: "#",
        },
        {
            user: { initials: "ОЛ", name: "Оксана Л." },
            date: "16.02.2024",
            rating: 5,
            content: "Много хубав елексир, обичам го. Сайта кожа винаги!",
            productLink: "#",
        },
        {
            user: { initials: "AV", name: "Anelia V." },
            date: "13.02.2024",
            rating: 5,
            content: "Сбогом, целулит! Ползвала съм много продукти за борба с целулита, но този наистина работи. Олиото е с невероятен аромат, попива добре в кожата и я оставя изгладена и хидратирана",
            productLink: "#",
        },
        {
            user: { initials: "AV", name: "Anelia V." },
            date: "13.02.2024",
            rating: 5,
            content: "Amazing. За пореден път поръчвам този удивителен скраб. Прави кожата ми изключително мека, гладка и подхранена. Лесен за употреба, не оставя следи, а ароматът е божествен",
            productLink: "#",
        },
        {
            user: { initials: "РТ", name: "Роса Т." },
            date: "12.02.2024",
            rating: 5,
            content: "Препоръчвам! Ароматът е уникален, действието- още повече!",
            productLink: "#",
        },
        {
            user: { initials: "РТ", name: "Роса Т." },
            date: "12.02.2024",
            rating: 5,
            content: "Препоръчвам! Продуктът е чудесен, вече взимам трета опаковка, резултатите са удивителни!",
            productLink: "#",
        },
        {
            user: { initials: "AD", name: "Angelina D." },
            date: "11.02.2024",
            rating: 5,
            content: "Много хубав продукт. За пръв път ползвам серум с хиалуронова киселина, който да има аромат, но съм доста приятно изненадана, ароматът много ми харесва, а серума също е много хубав, кожата се усеща плътна и подхранена",
            productLink: "#",
        },
        {
            user: { initials: "ГА", name: "Габриела А." },
            date: "31.01.2024",
            rating: 5,
            content: "Страхотни продукти! Благодаря!",
            productLink: "#",
        },
        {
            user: { initials: "ПИ", name: "Полина И." },
            date: "22.01.2024",
            rating: 5,
            content: "Уникален продукт. Очаквах, че косата ще се омазнява, предвид консистенцията, но се оказа, че няма такова нещо, напротив- косата е мека, лека и жизнена. Ползвам го и на влажна, и на суха коса, и ефекта е Уау :) още повече, че имам облекчение на скалпа в предната част на главата, където има постоянно лющене на кожата, поради себореен дерматит.",
            productLink: "#",
        }
    ];
    

    return (
        <div className="bg-[#f6f3f0] p-8 text-start">
            <h2 className="text-4xl text-[#816c65] ml-60">ПОТРЕБИТЕЛСКИ ОТЗИВИ</h2>
            <p className="text-sm text-[#816c65] mt-2 ml-60">18 369 мнения, от които 2 299 от български клиенти</p>
            <div className="mt-8 text-left ml-60 mr-60">
                {commentsData.map((comment, index) => (
                    <Comment key={index} {...comment} />
                ))}
            </div>
        </div>
    );
}

export default CommentsSection;
